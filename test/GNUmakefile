CURRY_TOP = ..


.PHONY: all clean info

#MODULES_DIRS =


TEST_TARGETS := HelloWorldTest


.PHONY: all clean info


all: $(TEST_TARGETS)


clean: clean-compilation
	@echo " Cleaning all in $$(pwd)"
	-@/bin/rm -f $(TEST_TARGETS)


info:
	@echo "TEST_TARGETS = $(TEST_TARGETS)"


include $(CURRY_TOP)/GNUmakesettings.inc
