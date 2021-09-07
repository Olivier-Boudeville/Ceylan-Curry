# Here are gathered explicit (immediate, static) rules for Curry.
#
# See GNUmakerules-automatic.inc for their automatic (generic, pattern-based)
# counterparts.


# Prerequisite: CURRY_TOP must be set.


.PHONY: default-curry-rule clean-compilation


# The first non-generic, therefore default, rule:
default-curry-rule: all


clean-compilation:
	@echo " Cleaning compilation byproducts in $$(pwd)"
	-@/bin/rm -f *.hi *.o
