cmake_minimum_required(VERSION 3.15)

project(HELIO_SEQUENCER VERSION 0.0.1)

add_subdirectory(ThirdParty)

juce_add_gui_app(HelioSequencer
    # VERSION ...                       # Set this if the app version is different to the project version
    # ICON_BIG ...                      # ICON_* arguments specify a path to an image file to use as an icon
    # ICON_SMALL ...
    # DOCUMENT_EXTENSIONS ...           # Specify file extensions that should be associated with this app
    # COMPANY_NAME ...                  # Specify the name of the app's author
    PRODUCT_NAME "Helio Sequencer")     # The name of the final executable, which can differ from the target name

juce_generate_juce_header(HelioSequencer)

add_subdirectory(Source)

target_compile_definitions(HelioSequencer
    PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_gui_app` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_gui_app` call
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:HelioSequencer,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:HelioSequencer,JUCE_VERSION>")

file(GLOB_RECURSE HelioSequencerDataSources CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/Resources/*)
juce_add_binary_data(HelioSequencerData
        HEADER_NAME     BinaryData.h
        NAMESPACE       BinaryData
        SOURCES         ${HelioSequencerDataSources} )

target_link_libraries(HelioSequencer
    PRIVATE
        hopscotch_map

        HelioSequencerData
        juce::juce_gui_extra
        juce::juce_core
        juce::juce_audio_basics
        juce::juce_audio_formats
        juce::juce_audio_utils
        juce::juce_audio_devices
        juce::juce_dsp
        juce::juce_opengl
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
