# Here are gathered explicit (immediate, static) rules for Curry.
#
# See GNUmakerules-automatic.inc for their automatic (generic, pattern-based)
# counterparts.


# Prerequisite: CURRY_TOP must be set.


.PHONY: default-curry-rule clean-compilation                                   \
		all all-pre-hook all-recurse-pre-hook all-parallel-recurse all-recurse \
		test test-recurse                                                      \
		clean clean-recurse clean-compilation                                  \
		info-files


# The first non-generic, therefore default, rule:
default-curry-rule: all


# Defining the BASE_MAKEFILE variable in top makefiles allows to define a
# specific (parallel) 'all' rule for them, while other makefiles just recurse
# accordingly:
#
ifeq ($(BASE_MAKEFILE),true)

# CORE_COUNT defined in curry/GNUmakevars.inc:
#
# (add 'echo " Entering module directory $$m"' if needing to troubleshoot)
#
all: all-pre-hook
	@echo "  Building all, in parallel over $(CORE_COUNT) core(s), from $(PWD)"
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then cd $$m && \
		$(MAKE) -s all-recurse -j $(CORE_COUNT) && cd ..; else echo "     (directory $$m skipped)"; \
	fi); then exit 1; fi; done

#clean:
#	-@if [ -d "doc" ]; then cd doc && $(MAKE) -s clean; fi


else


all: all-recurse-pre-hook all-recurse


endif


# all*-pre-hook targets allow to insert arbitrary rules *before* other specified
# prerequisite targets, at each level.
#
# Meant to be enriched with prerequisite targets by above layers:

# Called once per layer, when starting compiling it:
all-pre-hook:


# Called once per subdirectory of the current layer, when starting compiling it:
all-recurse-pre-hook:



# This rule is not used by default, as we use the -j option from the root
# makefile, letting then 'make' use its job server for that task:
all-parallel-recurse:
	@echo "  Building all on parallel over $(CORE_COUNT) cores (in "$(PWD) #$$(basename $(PWD))
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then cd $$m && $(MAKE) -s all -j $(CORE_COUNT) CMD_LINE_OPT="${CMD_LINE_OPT}" && cd ..; else echo "    (directory $$m skipped)"; fi); then exit 1; fi; done


# Temporary:
all-recurse: $(TEST_TARGETS)
	@echo "  Building all in "$(PWD) #$$(basename $(PWD))
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then cd $$m && $(MAKE) -s all CMD_LINE_OPT="${CMD_LINE_OPT}" && cd ..; else echo "  (directory $$m skipped)"; fi); then exit 1; fi; done



test: all test-recurse
	@for t in $(TEST_TARGETS); do if ! ./$$t; then echo "Test failed." 1>&2; exit 1; else echo; fi; done


test-recurse:
	@echo "   Testing all in $$(basename $(PWD))"
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then cd $$m && $(MAKE) -s test CMD_LINE_OPT="${CMD_LINE_OPT}" && cd ..; else echo "	  (directory $$m skipped)"; fi); then exit 1; fi; done


ifeq ($(ROOT_MAKEFILE),true)

# Just more talkative:
clean-recurse:
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then        \
	echo "  Cleaning in '$$(basename $$m)' layer"; cd $$m &&       \
	$(MAKE) -s clean CMD_LINE_OPT="${CMD_LINE_OPT}" &&             \
	cd ..; else echo "    (directory $$m skipped)"; fi); then      \
	exit 1; fi; done

else

clean-recurse:
	@for m in $(MODULES_DIRS); do if ! (if [ -d $$m ]; then        \
	cd $$m && $(MAKE) -s clean CMD_LINE_OPT="${CMD_LINE_OPT}" &&   \
	cd ..; else echo "    (directory $$m skipped)"; fi); then      \
	exit 1; fi; done

endif


clean: clean-compilation clean-recurse

clean-compilation:
	@#echo " Cleaning compilation byproducts in $$(pwd)"
	-@/bin/rm -f *.hi *.o


info-files:
	@echo "ALL_HS_SOURCES = $(ALL_HS_SOURCES)"
	@echo "EXCLUDED_HS_SOURCES = $(EXCLUDED_HS_SOURCES)"
	@echo "HS_SOURCES = $(HS_SOURCES)"
	@echo "HS_TARGETS = $(HS_TARGETS)"
	@echo "TEST_HS_SOURCES = $(TEST_HS_SOURCES)"
	@echo "TEST_HS_TARGETS = $(TEST_HS_TARGETS)"