#pragma once

enum class TokenName
{
    UNIDENTIFIED,
    LET,
    IDENTIFIER,
    EQUALS,
    LITERAL,
    SEMICOLON,

    /* Leave at bottom! */
    TOKEN_COUNT
};