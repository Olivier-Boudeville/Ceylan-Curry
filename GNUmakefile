CURRY_TOP = .


.PHONY: help help-intro help-curry                                    \
		all clean                                                     \
		info info-versions info-tools


MODULES_DIRS = src doc #conf test


# To override the 'all' default target with a parallel version:
BASE_MAKEFILE = true


# First target for default:
help: help-intro help-curry


help-intro:
	@echo " Following main make targets are available for package $(PACKAGE_NAME):"


help-curry:
	@echo "  - 'all':        builds everything (recursively, from current directory)"
	@echo "  - 'clean':      cleans compiled code (recursively, from current directory)"
	@echo "  - 'real-clean': cleans everything (from the root of any package)"
	@echo "  - 'doc':        generates documentation"
	@echo "  - 'info':       displays make-related key variables"
	@echo "  - 'help':       displays this help"


all:


# Typically useful to know the software context for continuous integration:
info: info-versions info-tools

info-versions:
	@echo "CURRY_VERSION = $(CURRY_VERSION)"


info-tools:
	@echo "HASKELL_INTERPRETER = $(HASKELL_INTERPRETER)"
	@echo "HASKELL_COMPILER = $(HASKELL_COMPILER)"
	@echo "HASKELL_COMPILER_OPT = $(HASKELL_COMPILER_OPT)"

include $(CURRY_TOP)/GNUmakesettings.inc
