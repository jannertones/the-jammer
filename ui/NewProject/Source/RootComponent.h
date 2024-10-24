/*
  ==============================================================================
 /Users/tannerjones/the-jammer/ui/NewProject/Source/RootComponent.h
  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "RNBO.h"
#include "RNBO_JuceAudioProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/




class RootComponent  : public juce::Component,
                       public juce::Slider::Listener,
                       public juce::Button::Listener,
                       public juce::ComboBox::Listener,
public juce::Timer
{
public:
    //==============================================================================
    RootComponent ();
    ~RootComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setAudioProcessor(RNBO::JuceAudioProcessor *p);
    void updateSliderForParam(unsigned long index, double value);
    void timerCallback() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void visibilityChanged() override;

    // Binary resources:
    static const char* screenshot20240715At12_00_14am_png;
    static const int screenshot20240715At12_00_14am_pngSize;
    static const char* screenshot20240715At7_36_10pm_png;
    static const int screenshot20240715At7_36_10pm_pngSize;
    static const char* screenshot20240715At9_57_58pm_png;
    static const int screenshot20240715At9_57_58pm_pngSize;
    static const char* screenshot20240717At12_31_31am_png;
    static const int screenshot20240717At12_31_31am_pngSize;
    static const char* screenshot20240717At12_32_28am_png;
    static const int screenshot20240717At12_32_28am_pngSize;
    static const char* screenshot20240719At4_47_38am_png;
    static const int screenshot20240719At4_47_38am_pngSize;
    static const char* screenshot20240719At4_54_06am_png;
    static const int screenshot20240719At4_54_06am_pngSize;
    static const char* flip_jpg;
    static const int flip_jpgSize;
    static const char* screenshot20240719At5_02_57am_png;
    static const int screenshot20240719At5_02_57am_pngSize;
    static const char* screenshot20240719At5_03_07am_png;
    static const int screenshot20240719At5_03_07am_pngSize;
    static const char* screenshot20240719At5_03_16am_png;
    static const int screenshot20240719At5_03_16am_pngSize;
    static const char* perfectDosVga437Win_ttf;
    static const int perfectDosVga437Win_ttfSize;
    


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    
    RNBO::JuceAudioProcessor *processor = nullptr;
    HashMap<int, Slider *> slidersByParameterIndex;
    HashMap<int, ComboBox *> comboByParameterIndex;
    HashMap<int, Button *> buttonsByParameterIndex;
    //[/UserVariables]
    class CustomFontLookAndFeel : public LookAndFeel_V4
    {
    public:
        CustomFontLookAndFeel()
        {
            // without this custom Fonts won't work!!
            LookAndFeel::setDefaultSansSerifTypeface (getCustomFont().getTypeface());

            // This can be used as one way of setting a default font
            // setDefaultSansSerifTypeface (getCustomFont().getTypeface());
        }

        static const Font getCustomFont()
        {
            static auto typeface = Typeface::createSystemTypefaceFor (perfectDosVga437Win_ttf, perfectDosVga437Win_ttfSize);
            return Font (typeface);
        }

        Typeface::Ptr getTypefaceForFont (const Font& f) override
        {
            // This can be used to fully change/inject fonts.
            // For example: return different TTF/OTF based on weight of juce::Font (bold/italic/etc)
            return getCustomFont().getTypeface();
        }
    } customLookAndFeel;
    
    class BoxLookAndFeel : public juce::LookAndFeel_V3
    {
    public:
        Font getComboBoxFont (ComboBox& ) override
        {
            return getCommonMenuFont();
        }
        
        Font getPopupMenuFont() override
        {
            return getCommonMenuFont();
        }
        
    private:
        Font getCommonMenuFont()
        {
            return Font (CustomFontLookAndFeel::getCustomFont().withHeight (13.0f));
            //13
        }
    } boxLook;


    class OtherLookAndFeel : public juce::LookAndFeel_V4
    {
    public:
        juce::Font getLabelFont (juce::Label& label)
        {
            if (dynamic_cast<juce::Slider*> (label.getParentComponent()))
                return Font (CustomFontLookAndFeel::getCustomFont().withHeight (11.0f));
            //11
                
            return LookAndFeel_V4::getLabelFont (label);
        }
        
        void drawLinearSlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    g.fillAll (slider.findColour (Slider::backgroundColourId));
                    Path p;
                    p.addRectangle ((float) x, (float) y, sliderPos - x, (float) height);
                    auto baseColour = slider.findColour (Slider::backgroundColourId);
                    g.setColour (baseColour);
                    g.fillPath (p);
                    auto lineThickness = 0;
                    g.drawRect (slider.getLocalBounds ().toFloat (), lineThickness);
                    drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
                }

                void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    auto sliderRadius = (float) (getSliderThumbRadius (slider) - 2);
                    float kx, ky;
                    kx = sliderPos;
                    ky = y + height * 0.5f;
                    g.setColour (slider.findColour (Slider::thumbColourId));
                    Path triangle;
                    triangle.addTriangle(kx, ky - 5, kx - 6, ky + 5, kx + 6, ky + 5);
                    g.fillPath(triangle);
                }
    } otherLookAndFeel;

    class OtherLookAndFeel2 : public juce::LookAndFeel_V4
    {
    public:
        juce::Font getLabelFont (juce::Label& label)
        {
            if (dynamic_cast<juce::Slider*> (label.getParentComponent()))
                return Font (CustomFontLookAndFeel::getCustomFont().withHeight (11.0f));
            //11
            return LookAndFeel_V4::getLabelFont (label);
        }
        void drawLinearSlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    g.fillAll (slider.findColour (Slider::backgroundColourId));
                    Path p;
                    p.addRectangle ((float) x, (float) y, sliderPos - x, (float) height);
                    auto baseColour = slider.findColour (Slider::backgroundColourId);
                    g.setColour (baseColour);
                    g.fillPath (p);
                    auto lineThickness = 0;
                    g.drawRect (slider.getLocalBounds ().toFloat (), lineThickness);
                    drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
                }

                void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    auto sliderRadius = (float) (getSliderThumbRadius (slider) - 2);
                    float kx, ky;
                    kx = sliderPos;
                    ky = y + height * 0.5f;
                    g.setColour (slider.findColour (Slider::thumbColourId));
                    Path triangle;
                    triangle.addTriangle(kx, ky + 5, kx + 6, ky - 5, kx - 6, ky - 5);
                    g.fillPath(triangle);
                }
    } otherLookAndFeel2;

    class OtherLookAndFeel3 : public juce::LookAndFeel_V4
    {
    public:
       juce::Font getLabelFont (juce::Label& label)
        {
            if (dynamic_cast<juce::Slider*> (label.getParentComponent()))
                return Font (CustomFontLookAndFeel::getCustomFont().withHeight (11.0f));
           //11
            return LookAndFeel_V4::getLabelFont (label);
        }
        void drawLinearSlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    g.fillAll (slider.findColour (Slider::backgroundColourId));
                    Path p;
                    p.addRectangle ((float) x, (float) y, sliderPos - x, (float) height);
                    auto baseColour = slider.findColour (Slider::backgroundColourId);
                    g.setColour (baseColour);
                    g.fillPath (p);
                    auto lineThickness = 0;
                    g.drawRect (slider.getLocalBounds ().toFloat (), lineThickness);
                    drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
                }

                void drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override
                {
                    auto sliderRadius = (float) (getSliderThumbRadius (slider) - 2);
                    float kx, ky;
                    kx = sliderPos;
                    ky = y + height * 0.5f;
                    g.setColour (slider.findColour (Slider::thumbColourId));
                    Path rect;
                    rect.addQuadrilateral(kx, ky + 8, kx + 6, ky, kx, ky - 8, kx - 6, ky);
                    g.fillPath(rect);
                }
    } otherLookAndFeel3;
    //==============================================================================
    std::unique_ptr<juce::Label> juce__label58;
    std::unique_ptr<juce::Label> juce__label20;
    std::unique_ptr<juce::Label> juce__label19;
    std::unique_ptr<juce::Label> juce__label57;
    std::unique_ptr<juce::Label> juce__label21;
    std::unique_ptr<juce::Label> juce__label60;
    std::unique_ptr<juce::Label> juce__label38;
    std::unique_ptr<juce::Label> juce__label37;
    std::unique_ptr<juce::Label> juce__label59;
    std::unique_ptr<juce::Label> juce__label41;
    std::unique_ptr<juce::Label> juce__label61;
    std::unique_ptr<juce::Label> juce__label62;
    std::unique_ptr<juce::Label> juce__label23;
    std::unique_ptr<juce::Label> juce__label22;
    std::unique_ptr<juce::Label> juce__label24;
    std::unique_ptr<juce::Label> juce__label29;
    std::unique_ptr<juce::Label> juce__label30;
    std::unique_ptr<juce::Label> juce__label8;
    std::unique_ptr<juce::Label> juce__label31;
    std::unique_ptr<juce::Label> juce__label42;
    std::unique_ptr<juce::Label> juce__label25;
    std::unique_ptr<juce::Label> juce__label9;
    std::unique_ptr<juce::Label> juce__label48;
    std::unique_ptr<juce::Label> juce__label47;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::TextButton> juce__textButton;
    std::unique_ptr<juce::ComboBox> juce__comboBox;
    std::unique_ptr<juce::TextButton> juce__textButton3;
    std::unique_ptr<juce::Slider> juce__slider3;
    std::unique_ptr<juce::Slider> juce__slider4;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Slider> juce__slider7;
    std::unique_ptr<juce::Label> juce__label7;
    std::unique_ptr<juce::Label> juce__label10;
    std::unique_ptr<juce::Label> juce__label12;
    std::unique_ptr<juce::ComboBox> juce__comboBox2;
    std::unique_ptr<juce::Label> juce__label26;
    std::unique_ptr<juce::Label> juce__label28;
    std::unique_ptr<juce::TextButton> juce__textButton2;
    std::unique_ptr<juce::TextButton> juce__textButton4;
    std::unique_ptr<juce::Label> juce__label35;
    std::unique_ptr<juce::Label> juce__label36;
    std::unique_ptr<juce::TextButton> juce__textButton8;
    std::unique_ptr<juce::TextButton> juce__textButton9;
    std::unique_ptr<juce::Slider> juce__slider12;
    std::unique_ptr<juce::Slider> juce__slider13;
    std::unique_ptr<juce::Slider> juce__slider14;
    std::unique_ptr<juce::Slider> juce__slider15;
    std::unique_ptr<juce::Slider> juce__slider16;
    std::unique_ptr<juce::Slider> juce__slider17;
    std::unique_ptr<juce::Label> juce__label44;
    std::unique_ptr<juce::Label> juce__label39;
    std::unique_ptr<juce::Label> juce__label46;
    std::unique_ptr<juce::Label> juce__label49;
    std::unique_ptr<juce::Label> juce__label50;
    std::unique_ptr<juce::Label> juce__label63;
    std::unique_ptr<juce::Label> juce__label64;
    std::unique_ptr<juce::Label> juce__label65;
    std::unique_ptr<juce::Label> juce__label66;
    std::unique_ptr<juce::Label> juce__label67;
    std::unique_ptr<juce::Label> juce__label68;
    std::unique_ptr<juce::Label> juce__label69;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_1;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_2;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_3;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_4;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_5;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_6;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_7;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_8;
    juce::Image cachedImage_screenshot20240715At9_57_58pm_png_9;
    juce::Image cachedImage_screenshot20240719At4_54_06am_png_10;
    juce::Image cachedImage_flip_jpg_11;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RootComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

