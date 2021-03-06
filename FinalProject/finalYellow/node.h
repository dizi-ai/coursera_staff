#pragma once
#include "date.h"

#include <string>
#include <memory>

using namespace std;

enum class LogicalOperation {
    Or,
    And
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) = 0;
};


class EmptyNode : public Node {
public:
    bool Evaluate(const Date &date, const std::string &event) override;
};

class LogicalOperationNode : public Node{
public:
    LogicalOperationNode(const LogicalOperation& logical_operation,
                         const std::shared_ptr<Node> node1,
                         const std::shared_ptr<Node> node2):
            logical_op_(logical_operation),
            node1_(node1),
            node2_(node2) {};

    bool Evaluate(const Date &date, const std::string &event) override;

private:
    const LogicalOperation logical_op_;
    std::shared_ptr<Node> node1_, node2_;

};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& comp, const Date& date): comparison_(comp), date_(date) {};
    bool Evaluate(const Date &date, const std::string &event) override;

private:
    const Comparison comparison_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& comp, const std::string& event): comparison_(comp), event_(event) {};
    bool Evaluate(const Date &date, const std::string &event) override;

private:
    const Comparison comparison_;
    const std::string event_;
};