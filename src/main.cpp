#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    // 1. CHECKPOINT ALINDIĞINDA (SAVE)
    void checkpointActivated(CheckpointObject* checkpoint) {
        PlayLayer::checkpointActivated(checkpoint);

        if (Mod::get()->getSettingValue<bool>("auto-save") && this->m_isPlatformer) {
            int levelID = this->m_level->m_levelID;
            
            // Kaçıncı checkpoint'te olduğumuzu ve o anki süreyi (time) al
            size_t checkpointCount = this->m_checkpointArray->count();
            double time = this->m_time;

            // Geode Kalıcı Hafızasına Kaydet
            std::string keyCount = "save_count_" + std::to_string(levelID);
            std::string keyTime = "save_time_" + std::to_string(levelID);

            Mod::get()->setSavedValue(keyCount, static_cast<int64_t>(checkpointCount));
            Mod::get()->setSavedValue(keyTime, time);

            log::info("Platformer Save: Checkpoint #{} ve Süre ({}) kaydedildi!", checkpointCount, time);
        }
    }

    // 2. SEVİYE YÜKLENDİĞİNDE VEYA YENİDEN BAŞLADIĞINDA (LOAD)
    void resetLevel() {
        PlayLayer::resetLevel();

        if (Mod::get()->getSettingValue<bool>("auto-save") && this->m_isPlatformer) {
            int levelID = this->m_level->m_levelID;

            std::string keyCount = "save_count_" + std::to_string(levelID);
            std::string keyTime = "save_time_" + std::to_string(levelID);

            // Kayıtlı veri var mı kontrol et
            int64_t savedCount = Mod::get()->getSavedValue<int64_t>(keyCount, 0);
            double savedTime = Mod::get()->getSavedValue<double>(keyTime, 0.0);

            if (savedCount > 0) {
                // Kayıtlı süreye ayarla
                this->m_time = savedTime;

                log::info("Platformer Load: Checkpoint verileri yuklendi! Checkpoint Sayisi: {}, Sure: {}", savedCount, savedTime);
            }
        }
    }
};
