#pragma once
#include "config.h"

// MESSAGE DISPLAY
const int MESSAGE_TIMEOUT_US = 500000;

class OmxDisp
{
public:
    // Should make into function
    const char *legends[4] = {"", "", "", ""};
    int legendVals[4] = {0, 0, 0, 0};
    int dispPage = 0;
    const char *legendText[4] = {"", "", "", ""};
    bool useLegendString[4] = {false, false, false, false};
    String legendString[4] = {"12345", "12345", "12345", "12345"};


    OmxDisp();
    void setup();
    void clearDisplay();
    void drawStartupScreen();
    void displayMessage(String msg);
    void displayMessage(const char *msg);
    void displayMessagef(const char *fmt, ...);
    void displayMessageTimed(String msg, uint8_t secs);

    bool isMessageActive();

    void dispGridBoxes();
    void invertColor(bool flip);
    void dispValBox(int v, int16_t n, bool inv);
    void dispSymbBox(const char *v, int16_t n, bool inv);
    void dispGenericMode(int selected);

    void dispGenericMode2(uint8_t numPages, int8_t selectedPage, int8_t selectedParam, bool encSelActive);

    // Displays a label and page numbers
    void dispGenericModeLabel(const char* label, uint8_t numPages, int8_t selectedPage);
    void dispGenericModeLabelDoubleLine(const char* label1, const char* label2, uint8_t numPages, int8_t selectedPage);
    void dispGenericModeLabelSmallText(const char* label, uint8_t numPages, int8_t selectedPage);

    void dispChar16(const char* charArray[], uint8_t charCount, uint8_t selected, uint8_t numPages, int8_t selectedPage, bool encSelActive, bool showLabels, const char* labels[], uint8_t labelCount);

    // Renders values as bars
    void dispValues16(int8_t valueArray[], uint8_t valueCount, int8_t minValue, int8_t maxValue, bool centered, uint8_t selected, uint8_t numPages, int8_t selectedPage, bool encSelActive, bool showLabels, const char* labels[], uint8_t labelCount);

    // Displays slots for midifx or something else in future
    void dispSlots(const char* slotNames[], uint8_t slotCount, uint8_t selected, bool encSelActive, bool showLabels, const char* labels[], uint8_t labelCount);


    void dispLabelParams(int8_t selected, bool encSelActive, const char* labels[], uint8_t labelCount);
    void dispPageIndicators(int page, bool selected);
    void dispPageIndicators2(uint8_t numPages, int8_t selected);
    void dispMode();

    void testdrawrect();
    void drawLoading();

    void setDirty();
    bool isDirty() { return dirtyDisplay; }

    void showDisplay();

    void bumpDisplayTimer();

    void clearLegends();
    void setSubmode(int submode);

    void UpdateMessageTextTimer();

    void drawEuclidPattern(bool singleView, bool *pattern, uint8_t steps, uint8_t yPos, bool selected, bool isPlaying, uint8_t seqPos);

private:
    int hline = 8;
    int messageTextTimer = 0;
    bool dirtyDisplay = false;

    String currentMsg;

    elapsedMillis dirtyDisplayTimer = 0;
    unsigned long displayRefreshRate = 60;

    void u8g2centerText(const char *s, int16_t x, int16_t y, uint16_t w, uint16_t h);
    void u8g2leftText(const char *s, int16_t x, int16_t y, uint16_t w, uint16_t h);
    void u8g2centerNumber(int n, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void renderMessage();
};

extern OmxDisp omxDisp;