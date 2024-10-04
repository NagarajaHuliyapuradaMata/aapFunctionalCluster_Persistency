load(
      "@rules_cc//cc:defs.bzl"
   ,  "cc_library"
)

cc_library(
      name       = "aapFunctionalCluster_Persistency"
   ,  srcs       = ["aapFunctionalCluster_Persistency.cpp"]
#  ,  deps       = ["//repo_projects/pProjectFull/main_LATEST/source/SwcServiceEcuM:SwcServiceEcuM"]
   ,  hdrs       = [
            "interface_Persistency_FileStorage.hpp"
         ,  "interface_Persistency.hpp"
         ,  "interface_Persistency_KeyValueStorage.hpp"
         ,  "interface_Persistency_ReadAccessor.hpp"
         ,  "interface_Persistency_ReadWriteAccessor.hpp"
      ]
   ,  includes   = ["."]
   ,  visibility = ["//visibility:public"]
)

