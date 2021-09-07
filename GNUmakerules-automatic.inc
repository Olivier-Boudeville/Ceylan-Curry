# Here are gathered automatic (generic, pattern-based) rules for Curry.
#
# See GNUmakerules-explicit.inc for the explicit (immediate, static)
# counterparts.


# Prerequisite: CURRY_TOP must be set.


# Add all Curry-specific rules below.



# Allows any upper layer to override as a whole the Curry rules used to compile
# classes and other modules:
#
ifndef OVERRIDE_CURRY_BUILD_RULES


%: %.hs
	@echo "  Compiling $< to $@"
	@$(HASKELL_COMPILER) $(HASKELL_COMPILER_OPT) $<


endif
