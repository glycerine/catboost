LIBRARY()



SRCS(
    for_data_provider.cpp
)

PEERDIR(
    library/unittest

    catboost/libs/cat_feature
    catboost/libs/data_new
    catboost/libs/data_types
    catboost/libs/data_util
    catboost/libs/helpers
)

END()