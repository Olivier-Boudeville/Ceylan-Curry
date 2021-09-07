# Prerequisite: CURRY_TOP must be set.


# To understand why taking into account such conditionals requires to specify
# them first, and in each layer, rather than at the end of the last one, refer
# to the section about conditionals at the top of the GNUmakevars.inc of Myriad
# (although it is not a dependency of Curry).


# Overall settings section.

#EXECUTION_TARGET = production

ifndef EXECUTION_TARGET

	# Other possible value: production
	EXECUTION_TARGET = development

endif


ifeq ($(EXECUTION_TARGET),development)

	#$(info Execution target is development)

	ENABLE_DEBUG = true

else ifeq ($(EXECUTION_TARGET),production)

	#$(info Execution target is production)

	ENABLE_DEBUG = false

else

	$(error Invalid Curry execution target '$(EXECUTION_TARGET)'; expecting either 'development' or 'production')

endif



# Tells whether the debug mode will be activated for the next CURRY classes to
# be built (maximum performance versus extended checkings).
#
ifeq ($(ENABLE_DEBUG),true)
	ENABLE_CURRY_DEBUG_OPT = -Dcurry_debug_mode
else
	ENABLE_CURRY_DEBUG_OPT =
endif



# Defining (optional) layer-specific flags, typically used by in-code
# conditional compilation primitives (see cond_utils for their management):

# Topics covered by flags:
#  - xx (none yet)

# Defining debug flags (at least the most verbose are by default commented-out):
ifeq ($(ENABLE_DEBUG),true)
	#CURRY_DEBUG_FLAGS += -Dcurry_debug_xx
endif

# Defining check flags:
ifeq ($(EXECUTION_TARGET),development)
	# Does not exist: CURRY_CHECK_FLAGS += -Dcurry_check_xx
endif




# Useful to target for example the root of the current layer (ex: to locate the
# relevant, layer-local '_build' directory):
#
ifndef LAYER_TOP
	LAYER_TOP := $(CURRY_TOP)
endif


# Project section.

# PROJECT_NAME should be defined on a per-project basis.
ifndef PROJECT_NAME
	PROJECT_NAME := Ceylan-Curry
endif


# PROJECT_SHORT_NAME should be defined on a per-project basis.
ifndef PROJECT_SHORT_NAME
	PROJECT_SHORT_NAME := curry
endif


# The uniquely-defined version of this layer, for all uses (including rebar and
# hex):
#
CURRY_VERSION := 0.0.1


# PROJECT_VERSION should be defined on a per-project basis.
ifndef PROJECT_VERSION
	PROJECT_VERSION := $(CURRY_VERSION)
endif


ifndef PACKAGE_NAME
	PACKAGE_NAME := $(PROJECT_NAME)
endif


ifndef PACKAGE_TOP
	PACKAGE_TOP := $(MYRIAD_TOP)
endif


# Needed, exactly as is (make trick to specify space as a parameter):
space :=
space +=


ARCHIVE_ROOT := $$HOME/Archives/$(PROJECT_NAME)


# For full archives (including untracked files and VCS state):
ARCHIVE_FILE := $(ARCHIVE_ROOT)/$$(date +'%Y%m%d')-$(PROJECT_NAME).tar.xz

# For archives as considered by the VCS system (ex: non-staged files are not
# archived here):
#
VCS_ARCHIVE_FILE := $(ARCHIVE_ROOT)/$$(date +'%Y%m%d')-$(PROJECT_NAME).git-bundle

# For very light archives, just the bleeding edge of the current sources, with
# no VCS state:
#
LIGHT_ARCHIVE_FILE := $(ARCHIVE_ROOT)/$$(date +'%Y%m%d')-$(PROJECT_NAME)-light-archive.tar.xz


ARCHIVE_BRANCH_FILE := $(ARCHIVE_ROOT)/$$(date +'%Y%m%d')-$(PROJECT_NAME)-branch-$(shell basename $$(pwd)).tar.xz


SNAPSHOT_ARCHIVE_FILE := $(ARCHIVE_ROOT)/$$(date +'%Y%m%d')-$(PROJECT_NAME)-snapshot.tar.xz


ifndef PACKAGE_TOP
	PACKAGE_TOP := $(CURRY_TOP)
endif


# Interpreter section.

HASKELL_INTERPRETER := $$(which ghci 2>/dev/null)



# Compiler section.

HASKELL_COMPILER := $$(which ghc 2>/dev/null)

HASKELL_COMPILER_OPT := -dynamic



# Documentation section.

# PROJECT_ICON is a path to an icon file that will be copied on HTML generation:
ifdef PROJECT_ICON
	PROJECT_ICON_OPT := --icon-file $(PROJECT_ICON)
endif
