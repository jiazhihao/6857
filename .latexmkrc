push @cus_dep_list, "c tex 0 c2tex";

sub c2tex { system("pygmentize -P tabsize=4 -P mathescape -f latex -o $_[0].tex $_[0].c"); }
