push @cus_dep_list, "c tex 0 c2tex";

sub c2tex { system("pygmentize -P tabsize=4 -P mathescape -f latex $_[0].c | sed 's/{n}{nan}/{k+kt}{nan}/g' | sed 's/{n}{\\([a-z][a-z]nan\\)}/{n+nf}{\\1}/g' > $_[0].tex"); }
