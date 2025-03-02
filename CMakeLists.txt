cmake_minimum_required(VERSION 3.25)
project(ObjectsDetector)
set(CMAKE_CXX_STANDARD 17)

set(OpenCV_DIR /Users/lilei/ThirdParty/OpenCV/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV_DIR = ${OpenCV_DIR}")
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")

set(PROJECT_APPLICATION_PATH ${PROJECT_SOURCE_DIR})
configure_file(ProjectRootPath.h.in ../ProjectRootPath.h)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

set(MODULE_CONFIGURATION_HEADER
        Configuration/FeatureExtractFilterThreshold.h
        Configuration/ImagePreprocessingConfiguration.h
        Configuration/DetectConfiguration.h
        Configuration/Builder/DetectConfigurationBuilder.h
        Configuration/Director/DetectConfigurationDirector.h
        Configuration/SingleDetectConfiguration.h)
set(MODULE_CONFIGURATION_SOURCE
        Configuration/ImagePreprocessingConfiguration.cpp
        Configuration/FeatureExtractFilterThreshold.cpp
        Configuration/DetectConfiguration.inl
        Configuration/Builder/DetectConfigurationBuilder.cpp
        Configuration/Director/DetectConfigurationDirector.cpp
        Configuration/SingleDetectConfiguration.cpp
        Configuration/DetectConfiguration.cpp)
set(MODULE_DETECTOR_HEADER
        Detector/DeepLearning/DNNObjectsDetector.h
        Detector/IObjectsDetector.h
        Detector/Traditional/TraditionalObjectsDetector.h)
set(MODULE_DETECTOR_SOURCE
        Detector/DeepLearning/DNNObjectsDetector.cpp
        Detector/Traditional/TraditionalObjectsDetector.cpp)
set(MODULE_ENTITY_HEADER
        Entity/ObjectInfo.h
        Entity/Corner.h
        Entity/CenterPoint.h
        Entity/Size.h
        Entity/InfoShower.h
        Entity/ParamPair.h)
set(MODULE_ENTITY_SOURCE
        Entity/ObjectInfo.cpp
        Entity/CenterPoint.cpp
        Entity/Size.cpp
        Entity/Corner.cpp
        Entity/ParamPair.cpp)
set(MODULE_FILE_ASSISTANT_HEADER
        FileAssistant/IFileAssistant.h
        FileAssistant/FileAssistant.h
        FileAssistant/FileHandler.h
        FileAssistant/UnixOSFileAssistant.h
        FileAssistant/WindowsOSFileAssistant.h)
set(MODULE_FILE_ASSISTANT_SOURCE
        FileAssistant/FileAssistant.cpp
        FileAssistant/FileHandler.cpp
        FileAssistant/UnixOSFileAssistant.cpp
        FileAssistant/WindowsOSFileAssistant.cpp)
set(MODULE_PREPROCESSING_HEADER
        Preprocessing/IImagePreprocessing.h
        Preprocessing/ImagePreprocessing.h
        Preprocessing/PreprocessingStep.h
        Preprocessing/ImagePreprocessingHandler.h
        Preprocessing/IImagePreprocessingHandler.h)
set(MODULE_PREPROCESSING_SOURCE
        Preprocessing/ImagePreprocessing.inl
        Preprocessing/ImagePreprocessingHandler.cpp)
set(MODULE_UTIL_HEADER
        Util/DisplayHandler.h
        Util/IDisplayHandler.h
        Util/ImageStorage.h
        Util/IImageStorage.h
        Util/PlatformSupporter.h)
set(MODULE_UTIL_SOURCE
        Util/DisplayHandler.cpp
        Util/ImageStorage.cpp
        Util/PlatformSupporter.cpp)
add_executable(ObjectsDetector
        ObjectsDetector.cpp
        Singleton.inl
        Singleton.h
        ${MODULE_CONFIGURATION_HEADER}
        ${MODULE_CONFIGURATION_SOURCE}
        ${MODULE_DETECTOR_HEADER}
        ${MODULE_DETECTOR_SOURCE}
        ${MODULE_ENTITY_HEADER}
        ${MODULE_ENTITY_SOURCE}
        ${MODULE_FILE_ASSISTANT_HEADER}
        ${MODULE_FILE_ASSISTANT_SOURCE}
        ${MODULE_PREPROCESSING_HEADER}
        ${MODULE_PREPROCESSING_SOURCE}
        ${MODULE_UTIL_HEADER}
        ${MODULE_UTIL_SOURCE}
        )

target_link_libraries(ObjectsDetector ${OpenCV_LIBS})
