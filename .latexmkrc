push @cus_dep_list, "c tex 0 c2tex";

sub c2tex { system("pygmentize -f latex -P verboptions='fontsize=\\footnotesize' -o $_[0].tex $_[0].c"); }
