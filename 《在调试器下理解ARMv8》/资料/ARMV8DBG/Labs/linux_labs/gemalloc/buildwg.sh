gcc -g3 gemalloc.c ./ptmalloc2/libmalloc.a -o gemallocwg `pkg-config --cflags --libs gtk+-2.0 gthread-2.0`  -lX11
