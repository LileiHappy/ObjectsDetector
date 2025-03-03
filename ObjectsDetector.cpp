#include <vector>
#include <string>

#include "Detector/Traditional/TraditionalObjectsDetector.h"
#include "Configuration/Director/DetectConfigurationDirector.h"
#include "Preprocessing/IImagePreprocessing.h"
#include "ProjectRootPath.h"
#include "Util/PlatformSupporter.h"

int main() {
    std::string projectRootPath(PROJECT_ROOT_PATH);
    projectRootPath
        .append(std::string(1, PlatformSupporter::getFilePathSeparator()))
        .append("asset")
        .append(std::string(1, PlatformSupporter::getFilePathSeparator()));
    DetectConfigurationBuilder builder;
    builder
    .addDetectImagePath(projectRootPath + "please insert the path of your pending detect image")
            .addPreprocessingImageShow(false)
            .addIdLabel(true)
            .addFeatureExtractFilterThreshold(FeatureExtractFilterThreshold(200, 1e5, 10, 10, 10, 10))
            .addResize(static_cast<int>(PreprocessStepPriority::P_1), 0.2)
            .addGray(static_cast<int>(PreprocessStepPriority::P_2))
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_3), 3)
            .addBinary(static_cast<int>(PreprocessStepPriority::P_4), 127)
            .addDilate(static_cast<int>(PreprocessStepPriority::P_5), 3)
            .addErode(static_cast<int>(PreprocessStepPriority::P_6), 3)
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_7), 3)
            .addCanny(static_cast<int>(PreprocessStepPriority::P_8), 100, 200)
            .finishDetectConfiguration()
    .addDetectImagePath(projectRootPath + "please insert the path of your pending detect image")
            .addPreprocessingImageShow(false)
            .addIdLabel(true)
            .addFeatureExtractFilterThreshold(FeatureExtractFilterThreshold(200, 1e5, 10, 10, 10, 10))
            .addResize(static_cast<int>(PreprocessStepPriority::P_1), 0.2)
            .addGray(static_cast<int>(PreprocessStepPriority::P_2))
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_3), 3)
            .addBinary(static_cast<int>(PreprocessStepPriority::P_4), 127)
            .addDilate(static_cast<int>(PreprocessStepPriority::P_5), 3)
            .addErode(static_cast<int>(PreprocessStepPriority::P_6), 3)
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_7), 3)
            .addCanny(static_cast<int>(PreprocessStepPriority::P_8), 100, 200)
            .finishDetectConfiguration()
    .addDetectImagePath(projectRootPath + "please insert the path of your pending detect image")
            .addPreprocessingImageShow(false)
            .addIdLabel(true)
            .addFeatureExtractFilterThreshold(FeatureExtractFilterThreshold(200, 1e5, 10, 10, 10, 10))
            .addResize(static_cast<int>(PreprocessStepPriority::P_1), 0.2)
            .addGray(static_cast<int>(PreprocessStepPriority::P_2))
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_3), 3)
            .addBinary(static_cast<int>(PreprocessStepPriority::P_4), 127)
            .addDilate(static_cast<int>(PreprocessStepPriority::P_5), 3)
            .addErode(static_cast<int>(PreprocessStepPriority::P_6), 3)
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_7), 3)
            .addCanny(static_cast<int>(PreprocessStepPriority::P_8), 100, 200)
            .finishDetectConfiguration()
    .addDetectImagePath(projectRootPath + "please insert the path of your pending detect image")
            .addPreprocessingImageShow(false)
            .addFeatureExtractFilterThreshold(FeatureExtractFilterThreshold(16, 1e5, 4, 4, 0, 0))
            .addResize(static_cast<int>(PreprocessStepPriority::P_1), 0.2)
            .addGray(static_cast<int>(PreprocessStepPriority::P_2))
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_3), 3)
            .addBinary(static_cast<int>(PreprocessStepPriority::P_4), 48)
//            .addDilate(static_cast<int>(PreprocessStepPriority::P_5), 3)
//            .addErode(static_cast<int>(PreprocessStepPriority::P_6), 3)
//            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_7), 3)
            .addCanny(static_cast<int>(PreprocessStepPriority::P_8), 200, 255)
            .finishDetectConfiguration()
    .addDetectImagePath(projectRootPath + "please insert the path of your pending detect image")
            .addPreprocessingImageShow(false)
            .addFeatureExtractFilterThreshold(FeatureExtractFilterThreshold(6, 1e5, 2, 2, 0, 0))
            .addResize(static_cast<int>(PreprocessStepPriority::P_1), 0.2)
            .addGray(static_cast<int>(PreprocessStepPriority::P_2))
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_3), 3)
            .addBinary(static_cast<int>(PreprocessStepPriority::P_4), 66)
            .addDilate(static_cast<int>(PreprocessStepPriority::P_5), 3)
            .addErode(static_cast<int>(PreprocessStepPriority::P_6), 3)
            .addGaussBlur(static_cast<int>(PreprocessStepPriority::P_7), 3)
            .addCanny(static_cast<int>(PreprocessStepPriority::P_8), 100, 200)
            .finishDetectConfiguration();
    DetectConfigurationDirector director{builder};
    DetectConfiguration configuration = director.createDetectConfiguration();

    std::unique_ptr<IObjectsDetector> detector(new TraditionalObjectsDetector());
    detector->detect(configuration);
    return 0;
}
