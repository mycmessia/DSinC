one_way_linked_list.out: main.o one_way_linked_list.o
	gcc $^ -o $@

main.o: one_way_linked_list.h
one_way_linked_list.o: one_way_linked_list.h


clean:
	-rm *.o
	-rm *.out
	-rm -rf *.out.dSYM
.PHONY: clean
