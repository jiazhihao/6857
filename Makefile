LATEXMK=scripts/latexmk
ASPELL_CMDS=\
	--add-tex-command='bibliography p' \
	--add-tex-command='bibliographystyle p' \
	--add-tex-command='fvset p' \
	--add-tex-command='renewcommand pp'

all:
	$(LATEXMK) -pdf p

clean:
	$(LATEXMK) -C

spell:
	@ for i in *.tex; do aspell -t $(ASPELL_CMDS) -p ./aspell.words -c $$i; done
	@ for i in *.tex; do scripts/double.pl $$i; done
	@ for i in *.tex; do scripts/abbrv.pl  $$i; done
	@ bash scripts/hyphens.sh *.tex
	@ ( head -1 aspell.words ; tail -n +2 aspell.words | sort ) > aspell.words~
	@ mv aspell.words~ aspell.words
