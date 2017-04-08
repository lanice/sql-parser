#ifndef __SQLPARSER__SQLPARSER_RESULT_H__
#define __SQLPARSER__SQLPARSER_RESULT_H__

#include "sql/SQLStatement.h"

namespace hsql {
  // Represents the result of the SQLParser.
  // If parsing was successful it contains a list of SQLStatement.
  class SQLParserResult {
   public:
    // Initialize with empty statement list.
    SQLParserResult();

    // Initialize with a single statement.
    // Takes ownership of the statement.
    SQLParserResult(SQLStatement* stmt);

    // Deletes all statements in the result.
    virtual ~SQLParserResult();

    // Set whether parsing was successful.
    void setIsValid(bool isValid);

    // Returns true if parsing was successful.
    bool isValid() const;

    // Returns the number of statements in the result.
    size_t size() const;

    // Set the details of the error, if available.
    // Takes ownership of errorMsg.
    void setErrorDetails(char* errorMsg, int errorLine, int errorColumn);

    // Returns the error message, if an error occurred.
    const char* errorMsg() const;

    // Returns the line number of the occurrance of the error in the query.
    int errorLine() const;

    // Returns the column number of the occurrance of the error in the query.
    int errorColumn() const;

    // Adds a statement to the result list of statements.
    // SQLParserResult takes ownership of the statement.
    void addStatement(SQLStatement* stmt);

    // Gets the SQL statement with the given index.
    const SQLStatement* getStatement(int index) const;

    // Gets the non const SQL statement with the given index.
    SQLStatement* getMutableStatement(int index);

    // Get the list of all statements.
    const std::vector<SQLStatement*>& getStatements() const;

    // Returns a copy of the list of all statements in this result.
    // Removes them from this result.
    std::vector<SQLStatement*> releaseStatements();

    // Deletes all statements and other data within the result.
    void reset();

   private:
    // List of statements within the result.
    std::vector<SQLStatement*> statements_;

    // Flag indicating the parsing was successful.
    bool isValid_;

    // Error message, if an error occurred.
    char* errorMsg_;

    // Line number of the occurrance of the error in the query.
    int errorLine_;

    // Column number of the occurrance of the error in the query.
    int errorColumn_;
  };

} // namespace hsql

#endif // __SQLPARSER__SQLPARSER_RESULT_H__