hellod: hellod.c libfoo.a
	g++ hellod.c -o hellod -L. -lfoo

libfoo.a: foo.o
	ar rv $@ $<

foo.o: foo.cc
	g++ $< -std=c++11 -c 

clean:
	rm -f *.o *.a hellod

install: hellod
	mkdir -p ${DESTDIR}usr/local/bin
	install -m 0755 hellod ${DESTDIR}usr/local/bin

.PHONE: clean install
