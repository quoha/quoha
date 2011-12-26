#include "local.h"

int PageBody(void) {
	printf("page body");
	return 0;
}

Command variables[] = {
	{ "pageBody" , PageBody },
	//"pageContentLeft" , "pageContentLeft",
	//"pageTabs" , "pageTabs",
	//"pageTitle", "Home Page",
	{ 0, 0 }
};

int
main(int argc, char *argv[])
{
	Chunk *c = BufferToChunk(ReadFile("template/page.tpl"));
	Chunk *pg = BufferToChunk(ReadFile("data/index.dat"));

	for (Chunk *p = c; p; p = p->next) {
		if (p->type == CHKTYPE_TEXT) {
			printf("%s", p->data);
		} else {
			printf("CODE(%s, ", p->data);
			for (int idx = 0; variables[idx].name; idx += 2) {
				if (strcmp(p->data, variables[idx].name) == 0) {
					variables[idx].func();
					break;
				}
			}
			printf(")");
		}
	}

	FILE *htm = OpenFile("/tmp/qindex.html", "w");

	fclose(htm);

	return 0;
}
