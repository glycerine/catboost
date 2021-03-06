# Generated by devtools/yamaker.

LIBRARY(expat)



VERSION(2.2.1)

LICENSE(MIT)

ADDINCL(
    contrib/libs/expat/lib
    contrib/libs/expat
)

NO_COMPILER_WARNINGS()

NO_UTIL()

IF (OS_WINDOWS)
    CFLAGS(
        GLOBAL -DXML_STATIC
    )
ELSE()
    CFLAGS(
        -DHAVE_EXPAT_CONFIG_H
    )
ENDIF()

SRCS(
    lib/xmlparse.c
    lib/xmlrole.c
    lib/xmltok.c
)

END()
