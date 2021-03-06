#include "oclint/AbstractASTVisitorRule.h"
#include "oclint/RuleSet.h"

#include "../abstract/AbstractEmptyBlockStmtRule.h"

using namespace std;
using namespace clang;
using namespace oclint;

class EmptySwitchStatementRule : public AbstractEmptyBlockStmtRule<EmptySwitchStatementRule>
{
private:
    static RuleSet rules;

public:
    virtual const string name() const override
    {
        return "empty switch statement";
    }

    virtual int priority() const override
    {
        return 2;
    }

    bool VisitSwitchStmt(SwitchStmt *switchStmt)
    {
        return checkLexicalEmptyStmt(switchStmt->getBody(), this);
    }
};

RuleSet EmptySwitchStatementRule::rules(new EmptySwitchStatementRule());
