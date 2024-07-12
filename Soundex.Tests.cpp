#include <gtest/gtest.h>
#include "generic_soundex.h"

// Test case to check if consonants are replaced with appropriate digits
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    GENERATE_SOUNDEX("AX", soundex);
    ASSERT_STREQ(soundex, "A200");
}

// Additional tests to verify different aspects of Soundex generation

// Test case to check the basic Soundex conversion
TEST(SoundexTestsuite, BasicConversion) {
    char soundex[5];
    GENERATE_SOUNDEX("Smith", soundex);
    ASSERT_STREQ(soundex, "S530");
}

// Test case to check if similar sounding names generate the same Soundex code
TEST(SoundexTestsuite, SimilarSoundingNames) {
    char soundex1[5];
    char soundex2[5];
    GENERATE_SOUNDEX("Robert", soundex1);
    GENERATE_SOUNDEX("Rupert", soundex2);
    ASSERT_STREQ(soundex1, soundex2);
}

// Test case to check if the name with different cases generates the same Soundex code
TEST(SoundexTestsuite, CaseInsensitive) {
    char soundex1[5];
    char soundex2[5];
    GENERATE_SOUNDEX("Ashcraft", soundex1);
    GENERATE_SOUNDEX("ashcraft", soundex2);
    ASSERT_STREQ(soundex1, soundex2);
}

// Test case to check if short names are padded with zeros
TEST(SoundexTestsuite, PadsShortNamesWithZeros) {
    char soundex[5];
    GENERATE_SOUNDEX("Pf", soundex);
    ASSERT_STREQ(soundex, "P100");
}

// Test case to check if names with vowels generate correct Soundex code
TEST(SoundexTestsuite, HandlesVowelsCorrectly) {
    char soundex[5];
    GENERATE_SOUNDEX("Euler", soundex);
    ASSERT_STREQ(soundex, "E460");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
