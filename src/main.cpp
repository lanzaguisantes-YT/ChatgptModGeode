#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

namespace {
constexpr auto kButtonNodeId = "chatgpt-custom-mod-button";

std::string configuredButtonLabel() {
    auto label = Mod::get()->getSettingValue<std::string>("button-label");
    if (label.empty()) {
        return "ChatGPT Mod";
    }
    return label;
}

void showAboutPopup() {
    FLAlertLayer::create(
        "ChatGPT Custom Mod",
        "<cy>¡Hola!</c> Este mod de ejemplo añade un botón personalizado al menú principal.\n\n"
        "Puedes cambiar el texto del botón desde la configuración del mod en Geode.",
        "Aceptar"
    )->show();
}
} // namespace

class $modify(ChatGPTMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto menu = this->getChildByID("bottom-menu");
        if (!menu) {
            log::warn("No se encontró bottom-menu; no se pudo añadir el botón de ChatGPT Custom Mod.");
            return true;
        }

        auto buttonSprite = ButtonSprite::create(configuredButtonLabel().c_str(), "goldFont.fnt", "GJ_button_01.png", 0.8f);
        auto button = CCMenuItemSpriteExtra::create(
            buttonSprite,
            this,
            menu_selector(ChatGPTMenuLayer::onChatGPTCustomMod)
        );
        button->setID(kButtonNodeId);
        menu->addChild(button);
        menu->updateLayout();

        if (Mod::get()->getSettingValue<bool>("show-welcome-popup")) {
            this->runAction(CCSequence::create(
                CCDelayTime::create(0.35f),
                CCCallFunc::create(this, callfunc_selector(ChatGPTMenuLayer::showWelcomePopup)),
                nullptr
            ));
        }

        return true;
    }

    void onChatGPTCustomMod(CCObject*) {
        showAboutPopup();
    }

    void showWelcomePopup() {
        FLAlertLayer::create(
            "ChatGPT Custom Mod",
            "Mod cargado correctamente. Pulsa el botón <cy>ChatGPT Mod</c> para ver más información.",
            "OK"
        )->show();
    }
};
