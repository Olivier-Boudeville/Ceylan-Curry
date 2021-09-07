CURRY_TOP = ..


.PHONY: all clean info

#MODULES_DIRS =


TARGET_EXECS := HelloWorld


.PHONY: all clean info


all: $(TARGET_EXECS)


clean: clean-compilation
	@echo " Cleaning all in $$(pwd)"
	-@/bin/rm -f $(TARGET_EXECS)


info:
	@echo "TARGET_EXECS = $(TARGET_EXECS)"


include $(CURRY_TOP)/GNUmakesettings.inc
