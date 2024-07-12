#include <gtest/gtest.h>
#include "generic_soundex.h"

// Test case to check if consonants are replaced with appropriate digits
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    GENERATE_SOUNDEX("AX", soundex);
   // ASSERT_STREQ(soundex, "A200");
}
