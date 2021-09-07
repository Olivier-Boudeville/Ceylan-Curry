CURRY_TOP = ..


DOC_BASE_NAME := Ceylan-Curry-cookbook-english

OVERALL_DOCUMENT_SOURCE := $(DOC_BASE_NAME).rst


CURRENT_CURRY_HTML := $(DOC_BASE_NAME).html

HTML_TARGET := $(CURRENT_CURRY_HTML)


CURRENT_CURRY_PDF := $(DOC_BASE_NAME).pdf

PDF_TARGET := $(CURRENT_CURRY_PDF)


DOC_GENERATED_FILES := $(HTML_TARGET) $(PDF_TARGET)



PROJECT_CSS := pygments-default.css,curry.css

PROJECT_ICON := curry-icon.png


# Read from the user's environment:
GITHUB_PAGES_BASE := $(shell basename "$(CURRY_WEB_MIRROR_BRANCH)")



.PHONY: all doc html pdf create-links clone-mirror                     \
		export-doc export-doc-to-official export-doc-to-mirror         \
		clean-links-local info info-web



# Default do-nothing target:
all:
	@echo "  Run 'make doc' to generate the documentation of the 'Curry' cookbook."


doc: html pdf

html: local-html

pdf: local-pdf


# These links do not need to be in version control:
create-links:
	@/bin/ln -sf $(CURRENT_CURRY_HTML) curry.html
	@/bin/ln -sf curry.html index.html
	@/bin/ln -sf $(CURRENT_CURRY_PDF) curry.pdf



# Creates a separate repository for the GitHub pages branch:
clone-mirror:
	@echo "  Creating a separate repository for website in $(CURRY_WEB_MIRROR_BRANCH)"
	@cd ../../ && git clone https://github.com/Olivier-Boudeville/Ceylan-Curry.git $(GITHUB_PAGES_BASE) && cd $(GITHUB_PAGES_BASE) && git checkout --orphan gh-pages
	@echo "Please specify your user settings (with git config) in that new branch."


export-doc: clean-doc doc export-doc-to-official export-doc-to-mirror


# Drawback: scp will not preserve symlinks, it will duplicate files instead.
#
# rsync would not, but requires a different source layout (copies a full tree,
# not a set of files), so currently not used:
# rsync -avze "ssh $(SP)" $(SOME_WEB_TREE) $(WEB_SRV):$(WEB_ROOT)/Curry/
#
export-doc-to-official: clean-doc create-links doc
	@echo "   Exporting Curry documentation to official website ($(WEB_SRV))"
	@/bin/scp $(SP) -r $(WEB_CONTENT) $(WEB_SRV):$(WEB_ROOT)/Curry/


export-doc-to-mirror: clean-doc create-links doc
	@echo "   Exporting Curry documentation to mirror website in $(CURRY_WEB_MIRROR_BRANCH)"
	@/bin/cp -rf $(WEB_CONTENT) $(CURRY_WEB_MIRROR_BRANCH) && cd $(CURRY_WEB_MIRROR_BRANCH) && git add . && git merge -s ours && git commit -m "Curry doc updated." && git push && git pull --ff-only


clean-links: clean-links-local

clean-links-local:
	-@/bin/rm -f curry.html curry.pdf



info: info-doc info-web


info-web:
	@echo "HTML_TARGET = $(HTML_TARGET)"
	@echo "SP = $(SP)"
	@echo "WEB_CONTENT = $(WEB_CONTENT)"
	@echo "WEB_SRV = $(WEB_SRV)"
	@echo "WEB_ROOT = $(WEB_ROOT)"
	@echo "CURRY_WEB_MIRROR_BRANCH = $(CURRY_WEB_MIRROR_BRANCH)"
	@echo "GITHUB_PAGES_BASE = $(GITHUB_PAGES_BASE)"


DOCUTILS_TOP = .

# Curry does not depend on Myriad, except for doc generation. So we define only
# here the (optional) path to the Myriad layer (possibly available as a symbolic
# link).
#
ifneq ($(wildcard $(CURRY_TOP)/../myriad/.),)
	MYRIAD_TOP = $(CURRY_TOP)/../myriad
	include $(MYRIAD_TOP)/doc/GNUmakerules-docutils.inc
endif

include $(CURRY_TOP)/GNUmakesettings.inc
