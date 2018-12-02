/* Generated By:JavaCC: Do not edit this line. ErrorHandler.h Version 6.2 */
/* JavaCCOptions:STATIC=false,SUPPORT_CLASS_VISIBILITY_PUBLIC=true,BUILD_PARSER=true,BUILD_TOKEN_MANAGER=true */
#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <stdio.h>
#include <string>
#include "JavaCC.h"
#include "Token.h"

namespace vhdl {
namespace parser {

JAVACC_SIMPLE_STRING addUnicodeEscapes(JAVACC_STRING_TYPE str);

  class VhdlParser;
  class ErrorHandler {
    friend class VhdlParserTokenManager;
    friend class VhdlParser;
    protected:
      int error_count;
    public:
      // Called when the parser encounters a different token when expecting to
      // consume a specific kind of token.
      // expectedKind - token kind that the parser was trying to consume.
      // expectedToken - the image of the token - tokenImages[expectedKind].
      // actual - the actual token that the parser got instead.
      virtual void handleUnexpectedToken(int expectedKind, JAVACC_STRING_TYPE expectedToken, Token *actual, VhdlParser *parser) {
        error_count++;
        fprintf(stderr, "Expecting %s at: %d:%d but got %s\n", addUnicodeEscapes(expectedToken).c_str(), actual->beginLine, actual->beginColumn, addUnicodeEscapes(actual->image).c_str());
      }
      // Called when the parser cannot continue parsing.
      // last - the last token successfully parsed.
      // unexpected - the token at which the error occurs.
      // production - the production in which this error occurrs.
      virtual void handleParseError(Token *last, Token *unexpected, JAVACC_SIMPLE_STRING production, VhdlParser *parser) {
        error_count++;
        fprintf(stderr, "Encountered: %s at: %d:%d while parsing: %s\n", addUnicodeEscapes(unexpected->image).c_str(), unexpected->beginLine, unexpected->beginColumn, production.c_str());
      }
      virtual int getErrorCount() {
        return error_count;
      }
      virtual void handleOtherError(JAVACC_STRING_TYPE message, VhdlParser *parser) {
        fprintf(stderr, "Error: %s\n", (char*)message.c_str());
      }
      virtual ~ErrorHandler() {}
      ErrorHandler() { error_count = 0; }
  };

  class VhdlParserTokenManager;
  class TokenManagerErrorHandler {
    friend class VhdlParserTokenManager;
    protected:
      int error_count;
    public:
       // Returns a detailed message for the Error when it is thrown by the
       // token manager to indicate a lexical error.
       // Parameters :
       //    EOFSeen     : indicates if EOF caused the lexical error
       //    curLexState : lexical state in which this error occurred
       //    errorLine   : line number when the error occurred
       //    errorColumn : column number when the error occurred
       //    errorAfter  : prefix that was seen before this error occurred
       //    curchar     : the offending character
       //
       virtual void lexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, JAVACC_STRING_TYPE errorAfter, JAVACC_CHAR_TYPE curChar, VhdlParserTokenManager* token_manager) {
        // by default, we just print an error message and return.
        fprintf(stderr, "Lexical error at: %d:%d. Encountered: %c after: %s.\n", errorLine, errorColumn, curChar, (EOFSeen? "EOF" : (const char*)errorAfter.c_str()));
      }
       virtual void lexicalError(JAVACC_STRING_TYPE errorMessage, VhdlParserTokenManager* token_manager) {
        fprintf(stderr, "%s\n", (char*)errorMessage.c_str());
      }
      virtual ~TokenManagerErrorHandler() {}
  };

}
}

#endif
/* JavaCC - OriginalChecksum=c18f1105ba178be8e21cc9f279f94496 (do not edit this line) */