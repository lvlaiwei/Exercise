
CFLAG += -g 
content=tmp bin lib

define make_model
	$(MAKE) -C $(subst src,, $(addprefix $(shell pwd), $(subst ./,/,$(dir $(shell find -name "$(1).c")))))
endef

all:single_list_data single_list_algorithm_reverse

single_list_data:
	$(call make_model,single_list_data)
	
single_list_algorithm_reverse:
	$(call make_model,single_list_algorithm_reverse)

clean:
	@for i in $(content); do \
		find -name "$$i" | xargs rm -r ; \
	done; 
