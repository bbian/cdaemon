hellod: hellod.c
		gcc hellod.c -o hellod

clean:
		rm -f *.o hellod

install: hellod
	mkdir -p ${DESTDIR}usr/local/bin
	install -m 0755 hellod ${DESTDIR}usr/local/bin

.PHONE: clean install
