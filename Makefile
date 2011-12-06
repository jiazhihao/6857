LATEXMK=scripts/latexmk
ASPELL_CMDS=\
	--add-tex-command="autoref p" \
	--add-tex-command='bibliography p' \
	--add-tex-command='bibliographystyle p' \
	--add-tex-command='fvset p' \
	--add-tex-command='lstset p' \
	--add-tex-command='mathrm p' \
	--add-tex-command='mathtt p' \
	--add-tex-command='newcommand pp' \
	--add-tex-command='renewcommand pp'

all:
	$(LATEXMK) -pdf p

code/fmt.tex:
	pygmentize -f latex -S default > $@~
	mv $@~ $@

clean:
	$(LATEXMK) -C

spell:
	@ for i in *.tex; do aspell -t $(ASPELL_CMDS) -p ./aspell.words -c $$i; done
	@ for i in *.tex; do scripts/double.pl $$i; done
	@ for i in *.tex; do scripts/abbrv.pl  $$i; done
	@ bash scripts/hyphens.sh *.tex
	@ ( head -1 aspell.words ; tail -n +2 aspell.words | sort ) > aspell.words~
	@ mv aspell.words~ aspell.words
