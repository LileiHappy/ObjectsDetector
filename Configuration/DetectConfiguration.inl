//
// Created by 李磊 on 2025/2/27.
//

void DetectConfiguration::clear() {
    m_detectConfigurations.clear();
    m_detectConfigurations.shrink_to_fit();
}
