DIRS = dpu host

.PHONY:	all $(DIRS)

all: $(DIRS)

$(DIRS):
	$(MAKE) -C $@

clean:
	$(MAKE) -C dpu clean
	$(MAKE) -C host clean
