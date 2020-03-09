if (HYPODERMIC_INCLUDE_DIR)
    set(HYPODERMIC_FOUND TRUE)
else(HYPODERMIC_INCLUDE_DIR)
    find_path(HYPODERMIC_INCLUDE_DIR
        NAMES Hypodermic.h
        PATHS /usr/include /usr/local/include ./lib/Hypodermic
        PATH_SUFFIXES Hypodermic
    )

    if (HYPODERMIC_INCLUDE_DIR)
        set(HYPODERMIC_FOUND TRUE)
    endif(HYPODERMIC_INCLUDE_DIR)

    if (HYPODERMIC_FOUND)
        message(STATUS "Found Hypodermic: ${HYPODERMIC_INCLUDE_DIR}")
        else(HYPODERMIC_FOUND)
        message(FATAL_ERROR "Could not find Hypodermic")
    endif(HYPODERMIC_FOUND)
endif(HYPODERMIC_INCLUDE_DIR)

set(HYPODERMIC_INCLUDE_DIR "${HYPODERMIC_INCLUDE_DIR}/.." )
