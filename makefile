hellod: hellod.c
		gcc hellod.c -o hellod

clean:
		rm -f *.o hellod

install: hellod
	install -m 0755 hellod ${DESTDIR}/usr/local/bin

.PHONE: clean install
