# This is the single file that all Curry GNUmakefiles, and only them, should
# include.

# Prerequisite: CURRY_TOP must be set.


# Each project should define its own GNUmakesettings.inc, as explained in
# myriad/GNUmakesettings.inc (Myriad is *not* a dependency of Curry).


# Nothing simpler can be used:


# First the make variables:

include $(CURRY_TOP)/GNUmakevars.inc


# Then rules are split between automatic (generic, pattern-based) ones and
# explicit (immediate, static) ones, so that the latter can be placed last
# (otherwise they would shadow any default target, such as 'all', defined by any
# lower layer, for instance when overriding base cleaning with their own
# 'clean-local' target):

include $(CURRY_TOP)/GNUmakerules-automatic.inc

include $(CURRY_TOP)/GNUmakerules-explicit.inc
