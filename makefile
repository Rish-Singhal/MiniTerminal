TARGET = bg.c fg.c okill.c kjob.c envf.c job.c pipe.c rdrec.c sighand.c cd.c  echo.c  execute.c  linere.c  ls.c  main.c  pinfo.c  pwd.c  strrep.c  strsplt.c  syscmd.c
PROGRAM  = shell

OBJECTS= $(TARGET:.c=.o)

all debug: $(PROGRAM)

 $(PROGRAM) : $(INCLUDES) $(OBJECTS)
	$(LINK.c) -o $@ $(OBJECTS) $(SLIBS)

clean:
	rm -f $(PROGRAM) $(OBJECTS)
