#pragma once

#ifndef DISABLE_PLAYFABENTITY_API

#include <playfab/PlayFabBaseModel.h>
#include <playfab/PlayFabJsonHeaders.h>

namespace PlayFabInternal
{
    namespace CloudScriptModels
    {
        // CloudScript Enums
        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void ToJsonEnum(const CloudScriptRevisionOption input, Json::Value& output)
        {
            if (input == CloudScriptRevisionOptionLive) output = Json::Value("Live");
            if (input == CloudScriptRevisionOptionLatest) output = Json::Value("Latest");
            if (input == CloudScriptRevisionOptionSpecific) output = Json::Value("Specific");
        }
        inline void FromJsonEnum(const Json::Value& input, CloudScriptRevisionOption& output)
        {
            if (!input.isString()) return;
            const std::string& inputStr = input.asString();
            if (inputStr == "Live") output = CloudScriptRevisionOptionLive;
            if (inputStr == "Latest") output = CloudScriptRevisionOptionLatest;
            if (inputStr == "Specific") output = CloudScriptRevisionOptionSpecific;
        }

        // CloudScript Classes
        struct EmptyResult : public PlayFabResultCommon
        {

            EmptyResult() :
                PlayFabResultCommon()
            {}

            EmptyResult(const EmptyResult&) :
                PlayFabResultCommon()
            {}

            ~EmptyResult() = default;

            void FromJson(Json::Value&) override
            {
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                return output;
            }
        };

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            ~EntityKey() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Id"], Id);
                FromJsonUtilS(input["Type"], Type);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Id; ToJsonUtilS(Id, each_Id); output["Id"] = each_Id;
                Json::Value each_Type; ToJsonUtilS(Type, each_Type); output["Type"] = each_Type;
                return output;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ~ScriptExecutionError() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["Error"], Error);
                FromJsonUtilS(input["Message"], Message);
                FromJsonUtilS(input["StackTrace"], StackTrace);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Error; ToJsonUtilS(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_Message; ToJsonUtilS(Message, each_Message); output["Message"] = each_Message;
                Json::Value each_StackTrace; ToJsonUtilS(StackTrace, each_StackTrace); output["StackTrace"] = each_StackTrace;
                return output;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            Json::Value Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            ~LogStatement() = default;

            void FromJson(Json::Value& input) override
            {
                Data = input["Data"];
                FromJsonUtilS(input["Level"], Level);
                FromJsonUtilS(input["Message"], Message);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                output["Data"] = Data;
                Json::Value each_Level; ToJsonUtilS(Level, each_Level); output["Level"] = each_Level;
                Json::Value each_Message; ToJsonUtilS(Message, each_Message); output["Message"] = each_Message;
                return output;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabResultCommon
        {
            Int32 APIRequestsIssued;
            Boxed<ScriptExecutionError> Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            Json::Value FunctionResult;
            Boxed<bool> FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            Boxed<bool> LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabResultCommon(),
                APIRequestsIssued(),
                Error(),
                ExecutionTimeSeconds(),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(),
                ProcessorTimeSeconds(),
                Revision()
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabResultCommon(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ~ExecuteCloudScriptResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["APIRequestsIssued"], APIRequestsIssued);
                FromJsonUtilO(input["Error"], Error);
                FromJsonUtilP(input["ExecutionTimeSeconds"], ExecutionTimeSeconds);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionResult = input["FunctionResult"];
                FromJsonUtilP(input["FunctionResultTooLarge"], FunctionResultTooLarge);
                FromJsonUtilP(input["HttpRequestsIssued"], HttpRequestsIssued);
                FromJsonUtilO(input["Logs"], Logs);
                FromJsonUtilP(input["LogsTooLarge"], LogsTooLarge);
                FromJsonUtilP(input["MemoryConsumedBytes"], MemoryConsumedBytes);
                FromJsonUtilP(input["ProcessorTimeSeconds"], ProcessorTimeSeconds);
                FromJsonUtilP(input["Revision"], Revision);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_APIRequestsIssued; ToJsonUtilP(APIRequestsIssued, each_APIRequestsIssued); output["APIRequestsIssued"] = each_APIRequestsIssued;
                Json::Value each_Error; ToJsonUtilO(Error, each_Error); output["Error"] = each_Error;
                Json::Value each_ExecutionTimeSeconds; ToJsonUtilP(ExecutionTimeSeconds, each_ExecutionTimeSeconds); output["ExecutionTimeSeconds"] = each_ExecutionTimeSeconds;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionResult"] = FunctionResult;
                Json::Value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output["FunctionResultTooLarge"] = each_FunctionResultTooLarge;
                Json::Value each_HttpRequestsIssued; ToJsonUtilP(HttpRequestsIssued, each_HttpRequestsIssued); output["HttpRequestsIssued"] = each_HttpRequestsIssued;
                Json::Value each_Logs; ToJsonUtilO(Logs, each_Logs); output["Logs"] = each_Logs;
                Json::Value each_LogsTooLarge; ToJsonUtilP(LogsTooLarge, each_LogsTooLarge); output["LogsTooLarge"] = each_LogsTooLarge;
                Json::Value each_MemoryConsumedBytes; ToJsonUtilP(MemoryConsumedBytes, each_MemoryConsumedBytes); output["MemoryConsumedBytes"] = each_MemoryConsumedBytes;
                Json::Value each_ProcessorTimeSeconds; ToJsonUtilP(ProcessorTimeSeconds, each_ProcessorTimeSeconds); output["ProcessorTimeSeconds"] = each_ProcessorTimeSeconds;
                Json::Value each_Revision; ToJsonUtilP(Revision, each_Revision); output["Revision"] = each_Revision;
                return output;
            }
        };

        struct ExecuteEntityCloudScriptRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FunctionName;
            Json::Value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            Boxed<Int32> SpecificRevision;

            ExecuteEntityCloudScriptRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteEntityCloudScriptRequest(const ExecuteEntityCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ~ExecuteEntityCloudScriptRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionParameter = input["FunctionParameter"];
                FromJsonUtilP(input["GeneratePlayStreamEvent"], GeneratePlayStreamEvent);
                FromJsonUtilE(input["RevisionSelection"], RevisionSelection);
                FromJsonUtilP(input["SpecificRevision"], SpecificRevision);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionParameter"] = FunctionParameter;
                Json::Value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output["GeneratePlayStreamEvent"] = each_GeneratePlayStreamEvent;
                Json::Value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output["RevisionSelection"] = each_RevisionSelection;
                Json::Value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output["SpecificRevision"] = each_SpecificRevision;
                return output;
            }
        };

        struct ExecuteFunctionRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FunctionName;
            Json::Value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;

            ExecuteFunctionRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent()
            {}

            ExecuteFunctionRequest(const ExecuteFunctionRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent)
            {}

            ~ExecuteFunctionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionParameter = input["FunctionParameter"];
                FromJsonUtilP(input["GeneratePlayStreamEvent"], GeneratePlayStreamEvent);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionParameter"] = FunctionParameter;
                Json::Value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output["GeneratePlayStreamEvent"] = each_GeneratePlayStreamEvent;
                return output;
            }
        };

        struct ExecuteFunctionResult : public PlayFabResultCommon
        {
            Int32 ExecutionTimeMilliseconds;
            std::string FunctionName;
            Json::Value FunctionResult;
            Boxed<bool> FunctionResultTooLarge;

            ExecuteFunctionResult() :
                PlayFabResultCommon(),
                ExecutionTimeMilliseconds(),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge()
            {}

            ExecuteFunctionResult(const ExecuteFunctionResult& src) :
                PlayFabResultCommon(),
                ExecutionTimeMilliseconds(src.ExecutionTimeMilliseconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge)
            {}

            ~ExecuteFunctionResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilP(input["ExecutionTimeMilliseconds"], ExecutionTimeMilliseconds);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FunctionResult = input["FunctionResult"];
                FromJsonUtilP(input["FunctionResultTooLarge"], FunctionResultTooLarge);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_ExecutionTimeMilliseconds; ToJsonUtilP(ExecutionTimeMilliseconds, each_ExecutionTimeMilliseconds); output["ExecutionTimeMilliseconds"] = each_ExecutionTimeMilliseconds;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                output["FunctionResult"] = FunctionResult;
                Json::Value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output["FunctionResultTooLarge"] = each_FunctionResultTooLarge;
                return output;
            }
        };

        struct FunctionModel : public PlayFabBaseModel
        {
            std::string FunctionName;
            std::string FunctionUrl;

            FunctionModel() :
                PlayFabBaseModel(),
                FunctionName(),
                FunctionUrl()
            {}

            FunctionModel(const FunctionModel& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                FunctionUrl(src.FunctionUrl)
            {}

            ~FunctionModel() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FromJsonUtilS(input["FunctionUrl"], FunctionUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                Json::Value each_FunctionUrl; ToJsonUtilS(FunctionUrl, each_FunctionUrl); output["FunctionUrl"] = each_FunctionUrl;
                return output;
            }
        };

        struct ListFunctionsRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;

            ListFunctionsRequest() :
                PlayFabRequestCommon(),
                Entity()
            {}

            ListFunctionsRequest(const ListFunctionsRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity)
            {}

            ~ListFunctionsRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                return output;
            }
        };

        struct ListFunctionsResult : public PlayFabResultCommon
        {
            std::list<FunctionModel> Functions;

            ListFunctionsResult() :
                PlayFabResultCommon(),
                Functions()
            {}

            ListFunctionsResult(const ListFunctionsResult& src) :
                PlayFabResultCommon(),
                Functions(src.Functions)
            {}

            ~ListFunctionsResult() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Functions"], Functions);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Functions; ToJsonUtilO(Functions, each_Functions); output["Functions"] = each_Functions;
                return output;
            }
        };

        struct RegisterHttpFunctionRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FunctionName;
            std::string FunctionUrl;

            RegisterHttpFunctionRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FunctionName(),
                FunctionUrl()
            {}

            RegisterHttpFunctionRequest(const RegisterHttpFunctionRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FunctionName(src.FunctionName),
                FunctionUrl(src.FunctionUrl)
            {}

            ~RegisterHttpFunctionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FunctionName"], FunctionName);
                FromJsonUtilS(input["FunctionUrl"], FunctionUrl);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                Json::Value each_FunctionUrl; ToJsonUtilS(FunctionUrl, each_FunctionUrl); output["FunctionUrl"] = each_FunctionUrl;
                return output;
            }
        };

        struct UnregisterFunctionRequest : public PlayFabRequestCommon
        {
            Boxed<EntityKey> Entity;
            std::string FunctionName;

            UnregisterFunctionRequest() :
                PlayFabRequestCommon(),
                Entity(),
                FunctionName()
            {}

            UnregisterFunctionRequest(const UnregisterFunctionRequest& src) :
                PlayFabRequestCommon(),
                Entity(src.Entity),
                FunctionName(src.FunctionName)
            {}

            ~UnregisterFunctionRequest() = default;

            void FromJson(Json::Value& input) override
            {
                FromJsonUtilO(input["Entity"], Entity);
                FromJsonUtilS(input["FunctionName"], FunctionName);
            }

            Json::Value ToJson() const override
            {
                Json::Value output;
                Json::Value each_Entity; ToJsonUtilO(Entity, each_Entity); output["Entity"] = each_Entity;
                Json::Value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output["FunctionName"] = each_FunctionName;
                return output;
            }
        };

    }
}

#endif
