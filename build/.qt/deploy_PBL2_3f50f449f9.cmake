include("D:/PBL/PBL2/PBL2/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/PBL2-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/PBL/PBL2/PBL2/build/PBL2.exe"
    GENERATE_QT_CONF
)
