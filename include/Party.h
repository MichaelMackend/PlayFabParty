#pragma once

#ifndef __cplusplus
#error "This header requires C++"
#endif // end if not defined __cplusplus

#include <PartyTypes.h>

#pragma push_macro("DEFINE_ENUM_FLAG_OPERATORS")
#ifndef DEFINE_ENUM_FLAG_OPERATORS
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
inline ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE((static_cast<int>(a)) | (static_cast<int>(b))); } \
inline ENUMTYPE &operator |= (ENUMTYPE &a, ENUMTYPE b) { return (a = a | b); } \
inline ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE((static_cast<int>(a)) & (static_cast<int>(b))); } \
inline ENUMTYPE &operator &= (ENUMTYPE &a, ENUMTYPE b) { return (a = a & b); } \
inline ENUMTYPE operator ~ (ENUMTYPE a) { return ENUMTYPE(~(static_cast<int>(a))); } \
inline ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE((static_cast<int>(a)) ^ (static_cast<int>(b))); } \
inline ENUMTYPE &operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (a = a ^ b); }
#endif

/// <summary>
/// Contains classes and enumerations for the Party library.
/// </summary>
namespace Party
{

class PartyLocalUser;
class PartyEndpoint;
class PartyLocalEndpoint;
class PartyDevice;
class PartyLocalDevice;
class PartyInvitation;
class PartyNetwork;
class PartyChatControl;
class PartyLocalChatControl;
class PartyTextToSpeechProfile;

/// <summary>
/// Convenience type for a constant array of PartyEndpoint pointers.
/// </summary>
/// <seealso cref="PartyEndpoint" />
typedef class PartyEndpoint * const * PartyEndpointArray;

/// <summary>
/// Convenience type for a constant array of PartyEndpoint pointers.
/// </summary>
/// <seealso cref="PartyEndpoint" />
typedef class PartyLocalEndpoint * const * PartyLocalEndpointArray;

/// <summary>
/// Convenience type for a constant array of PartyDevice pointers.
/// </summary>
/// <seealso cref="PartyDevice" />
typedef class PartyDevice * const * PartyDeviceArray;

/// <summary>
/// Convenience type for a constant array of PartyInvitation pointers.
/// </summary>
/// <seealso cref="PartyInvitation" />
typedef class PartyInvitation * const * PartyInvitationArray;

/// <summary>
/// Convenience type for a constant array of PartyNetwork pointers.
/// </summary>
/// <seealso cref="PartyNetwork" />
typedef class PartyNetwork * const * PartyNetworkArray;

/// <summary>
/// Convenience type for a constant array of PartyChatControl pointers.
/// </summary>
/// <seealso cref="PartyChatControl" />
typedef class PartyChatControl * const * PartyChatControlArray;

/// <summary>
/// Convenience type for a constant array of PartyChatControl pointers.
/// </summary>
/// <seealso cref="PartyChatControl" />
typedef class PartyLocalChatControl * const * PartyLocalChatControlArray;

/// <summary>
/// Convenience type for a constant array of PartyTextToSpeechProfile pointers.
/// </summary>
/// <seealso cref="PartyTextToSpeechProfile" />
typedef class PartyTextToSpeechProfile * const * PartyTextToSpeechProfileArray;

/// <summary>
/// Convenience type for a constant array of constant PartyStateChange pointers.
/// </summary>
/// <seealso cref="PartyNetwork" />
typedef const struct PartyStateChange * const * PartyStateChangeArray;

/// <summary>
/// Convenience type for a constant array of PartyLocalUser pointers.
/// </summary>
/// <seealso cref="PartyNetwork" />
typedef class PartyLocalUser * const * PartyLocalUserArray;

/// <summary>
/// The maximum allowed value for the <em>maxDeviceCount</em> field in the PartyNetworkConfiguration structure.
/// </summary>
/// <seealso cref="PartyNetworkConfiguration" />
constexpr uint32_t c_maxNetworkConfigurationMaxDeviceCount = 32;

/// <summary>
/// The maximum allowed value for the <em>maxEndpointsPerDeviceCount</em> field in the PartyNetworkConfiguration
/// structure.
/// </summary>
/// <seealso cref="PartyNetworkConfiguration" />
constexpr uint32_t c_maxNetworkConfigurationMaxEndpointsPerDeviceCount = 32;

/// <summary>
/// The maximum number of local users that can be created with PartyManager::CreateLocalUser().
/// </summary>
/// <seealso cref="PartyManager::CreateLocalUser" />
constexpr uint32_t c_maxLocalUsersPerDeviceCount = 8;

/// <summary>
/// Size of an opaque connection information binary blob.
/// </summary>
constexpr uint32_t c_opaqueConnectionInformationByteCount = 300;

/// <summary>
/// Maximum length in characters of a PartyInvitation identifier, not including the null terminator.
/// </summary>
/// <seealso cerf="PartyInvitationConfiguration" />
constexpr uint32_t c_maxInvitationIdentifierStringLength = 127;

/// <summary>
/// Maximum number of PlayFab Entity IDs on a single invitation.
/// </summary>
/// <seealso cerf="PartyInvitationConfiguration" />
constexpr uint32_t c_maxInvitationEntityIdCount = 1024;

/// <summary>
/// Maximum length in characters of an Entity ID, not including the null terminator
/// </summary>
constexpr uint32_t c_maxEntityIdStringLength = 20;

/// <summary>
/// Length in characters of a network identifier, not including the null terminator.
/// </summary>
constexpr uint32_t c_networkIdentifierStringLength = 36;

/// <summary>
/// Maximum length in characters of a region name, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxRegionNameStringLength = 19;

/// <summary>
/// Maximum length in characters of a serialized network descriptor, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxSerializedNetworkDescriptorStringLength = 448;

/// <summary>
/// Maximum length in characters of an audio device identifier, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxAudioDeviceIdentifierStringLength = 999;

/// <summary>
/// Maximum length in characters of a language code, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxLanguageCodeStringLength = 84;

/// <summary>
/// Maximum length in characters of a chat text message, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxChatTextMessageStringLength = 1023;

/// <summary>
/// Maximum length in characters of a chat transcription message, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxChatTranscriptionMessageStringLength = 1023;

/// <summary>
/// Maximum length in characters of a text to speech profile identifier, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxTextToSpeechProfileIdentifierStringLength = 255;

/// <summary>
/// Maximum length in characters of a text to speech profile name, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxTextToSpeechProfileNameStringLength = 127;

/// <summary>
/// Maximum length in characters of a text to speech synthesis input string, not including the null terminator.
/// </summary>
constexpr uint32_t c_maxTextToSpeechInputStringLength = 1023;

/// <summary>
/// A processor mask that represents all processors available to the title.
/// </summary>
constexpr uint64_t c_anyProcessor = 0xffffffffffffffff;

/// <summary>
/// The lowest allowed priority value for the <em>priority</em> field in the PartySendMessageQueuingConfiguration
/// structure.
/// </summary>
constexpr int8_t c_minSendMessageQueuingPriority = -5;

/// <summary>
/// The effective send message queuing configuration priority internally used to transmit chat data.
/// </summary>
/// <remarks>
/// Assign messages a priority value smaller than this to let chat take precedence over them when connection quality is
/// unable to support both. Assign messages a priority value larger than this for caller game data to take precedence.
/// </remarks>
constexpr int8_t c_chatSendMessageQueuingPriority = -3;

/// <summary>
/// The default send message priority when no PartySendMessageQueuingConfiguration structure has been provided.
/// </summary>
constexpr int8_t c_defaultSendMessageQueuingPriority = 0;

/// <summary>
/// The highest allowed priority value for the <em>priority</em> field in the PartySendMessageQueuingConfiguration
/// structure.
/// </summary>
constexpr int8_t c_maxSendMessageQueuingPriority = 5;

#pragma pack(push, 8)

/// <summary>
/// The types of state changes that can occur.
/// </summary>
enum class PartyStateChangeType : uint32_t
{
    /// <summary>
    /// The list of regions in which the title may create networks has changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRegionsChangedStateChange object for more information.
    /// </remarks>
    RegionsChanged,

    /// <summary>
    /// The operation started by a previous call to PartyManager::DestroyLocalUser() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDestroyLocalUserCompletedStateChange object for more
    /// information.
    /// </remarks>
    DestroyLocalUserCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyManager::CreateNewNetwork() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyCreateNewNetworkCompletedStateChange object for more
    /// information.
    /// </remarks>
    CreateNewNetworkCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyManager::ConnectToNetwork() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyConnectToNetworkCompletedStateChange object for more
    /// information.
    /// </remarks>
    ConnectToNetworkCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::AuthenticateLocalUser() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyAuthenticateLocalUserCompletedStateChange object for more
    /// information.
    /// </remarks>
    AuthenticateLocalUserCompleted,

    /// <summary>
    /// The network configuration associated with the PartyNetwork is now available.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyNetworkConfigurationMadeAvailableStateChange object for
    /// more information.
    /// </remarks>
    NetworkConfigurationMadeAvailable,

    /// <summary>
    /// The network descriptor associated with the PartyNetwork changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyNetworkDescriptorChangedStateChange object for more
    /// information.
    /// </remarks>
    NetworkDescriptorChanged,

    /// <summary>
    /// A local user has been removed from the network by a previous call to PartyNetwork::RemoveLocalUser() or
    /// PartyManager::DestroyLocalUser().
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyLocalUserRemovedStateChange object for more information.
    /// </remarks>
    LocalUserRemoved,

    /// <summary>
    /// The operation to remove a local user started by a previous call to PartyNetwork::RemoveLocalUser() or
    /// PartyManager::DestroyLocalUser() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRemoveLocalUserCompletedStateChange object for more
    /// information.
    /// </remarks>
    RemoveLocalUserCompleted,

    /// <summary>
    /// A local user was kicked via PartyNetwork::KickUser().
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyLocalUserKickedStateChange object for more information.
    /// </remarks>
    LocalUserKicked,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::CreateEndpoint() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyCreateEndpointCompletedStateChange object for more
    /// information.
    /// </remarks>
    CreateEndpointCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::DestroyEndpoint() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDestroyEndpointCompletedStateChange object for more
    /// information.
    /// </remarks>
    DestroyEndpointCompleted,

    /// <summary>
    /// A new endpoint was created.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyEndpointCreatedStateChange object for more information.
    /// </remarks>
    EndpointCreated,

    /// <summary>
    /// An endpoint was destroyed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyEndpointDestroyedStateChange object for more information.
    /// </remarks>
    EndpointDestroyed,

    /// <summary>
    /// A new remote device was created.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRemoteDeviceCreatedStateChange object for more information.
    /// </remarks>
    RemoteDeviceCreated,

    /// <summary>
    /// A remote device was destroyed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRemoteDeviceDestroyedStateChange object for more
    /// information.
    /// </remarks>
    RemoteDeviceDestroyed,

    /// <summary>
    /// A remote device joined a network.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRemoteDeviceJoinedNetworkStateChange object for more
    /// information.
    /// </remarks>
    RemoteDeviceJoinedNetwork,

    /// <summary>
    /// A remote device left a network.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRemoteDeviceLeftNetworkStateChange object for more
    /// information.
    /// </remarks>
    RemoteDeviceLeftNetwork,

    /// <summary>
    /// The properties associated with the device changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDevicePropertiesChangedStateChange object for more
    /// information.
    /// </remarks>
    DevicePropertiesChanged,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::LeaveNetwork() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyLeaveNetworkCompletedStateChange object for more
    /// information.
    /// </remarks>
    LeaveNetworkCompleted,

    /// <summary>
    /// A network was destroyed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyNetworkDestroyedStateChange object for more information.
    /// </remarks>
    NetworkDestroyed,

    /// <summary>
    /// A data send was received from an endpoint.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyEndpointMessageReceivedStateChange object for more
    /// information.
    /// </remarks>
    EndpointMessageReceived,

    /// <summary>
    /// The PartyDataBuffer set provided to SendMessage has been returned.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDataBuffersReturnedStateChange object for more information.
    /// </remarks>
    DataBuffersReturned,

    /// <summary>
    /// The properties associated with an endpoint changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyEndpointPropertiesChangedStateChange object for more
    /// information.
    /// </remarks>
    EndpointPropertiesChanged,

    /// <summary>
    /// An operation started by a call to PartyManager::SynchronizeMessagesBetweenEndpoints has completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySynchronizeMessagesBetweenEndpointsCompletedStateChange
    /// object for more information.
    /// </remarks>
    SynchronizeMessagesBetweenEndpointsCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::CreateInvitation() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyCreateInvitationCompletedStateChange object for more
    /// information.
    /// </remarks>
    CreateInvitationCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::RevokeInvitation() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyRevokeInvitationCompletedStateChange object for more
    /// information.
    /// </remarks>
    RevokeInvitationCompleted,

    /// <summary>
    /// A new invitation was created.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyInvitationCreatedStateChange object for more information.
    /// </remarks>
    InvitationCreated,

    /// <summary>
    /// An invitation was destroyed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyInvitationDestroyedStateChange object for more information.
    /// </remarks>
    InvitationDestroyed,

    /// <summary>
    /// The properties associated with the PartyNetwork changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyNetworkPropertiesChangedStateChange object for more
    /// information.
    /// </remarks>
    NetworkPropertiesChanged,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::KickDevice() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyKickDeviceCompletedStateChange object for more information.
    /// </remarks>
    KickDeviceCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::KickUser() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyKickUserCompletedStateChange object for more information.
    /// </remarks>
    KickUserCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalDevice::CreateChatControl() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyCreateChatControlCompletedStateChange object for more
    /// information.
    /// </remarks>
    CreateChatControlCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalDevice::DestroyChatControl() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDestroyChatControlCompletedStateChange object for more
    /// information.
    /// </remarks>
    DestroyChatControlCompleted,

    /// <summary>
    /// A new PartyChatControl was created.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatControlCreatedStateChange object for more information.
    /// </remarks>
    ChatControlCreated,

    /// <summary>
    /// A PartyChatControl was destroyed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatControlDestroyedStateChange object for more
    /// information.
    /// </remarks>
    ChatControlDestroyed,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetAudioEncoderBitrate() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetChatAudioEncoderBitrateCompletedStateChange object for
    /// more information.
    /// </remarks>
    SetChatAudioEncoderBitrateCompleted,

    /// <summary>
    /// Chat text has been received.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatTextReceivedStateChange object for more information.
    /// </remarks>
    ChatTextReceived,

    /// <summary>
    /// A voice chat transcription has been received.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyVoiceChatTranscriptionReceivedStateChange object for more
    /// information.
    /// </remarks>
    VoiceChatTranscriptionReceived,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetAudioInput() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetChatAudioInputCompletedStateChange object for more
    /// information.
    /// </remarks>
    SetChatAudioInputCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetAudioOutput() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetChatAudioOutputCompletedStateChange object for more
    /// information.
    /// </remarks>
    SetChatAudioOutputCompleted,

    /// <summary>
    /// The state of an audio input associated with a local chat control changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyLocalChatAudioInputChangedStateChange object for more
    /// information.
    /// </remarks>
    LocalChatAudioInputChanged,

    /// <summary>
    /// The state of an audio output associated with a local chat control changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyLocalChatAudioOutputChangedStateChange object for more
    /// information.
    /// </remarks>
    LocalChatAudioOutputChanged,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetTextToSpeechProfile() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetTextToSpeechProfileCompletedStateChange object for more
    /// information.
    /// </remarks>
    SetTextToSpeechProfileCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SynthesizeTextToSpeech() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySynthesizeTextToSpeechCompletedStateChange object for more
    /// information. Receiving a state change of this type indicates that the audio has been synthesized, not that the
    /// audio has been transmitted to anyone.
    /// </remarks>
    SynthesizeTextToSpeechCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetLanguage() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetLanguageCompletedStateChange object for more
    /// information.
    /// </remarks>
    SetLanguageCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetTranscriptionOptions() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetTranscriptionOptionsCompletedStateChange object for
    /// more information.
    /// </remarks>
    SetTranscriptionOptionsCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::SetTextChatOptions() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartySetTextChatOptionsCompletedStateChange object for more
    /// information.
    /// </remarks>
    SetTextChatOptionsCompleted,

    /// <summary>
    /// The properties associated with the chat control changed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatControlPropertiesChangedStateChange object for more
    /// information.
    /// </remarks>
    ChatControlPropertiesChanged,

    /// <summary>
    /// The chat control joined a network.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatControlJoinedNetworkStateChange object for more
    /// information.
    /// </remarks>
    ChatControlJoinedNetwork,

    /// <summary>
    /// The chat control left a network.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyChatControlLeftNetworkStateChange object for more
    /// information.
    /// </remarks>
    ChatControlLeftNetwork,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::ConnectChatControl() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyConnectChatControlCompletedStateChange object for more
    /// information.
    /// </remarks>
    ConnectChatControlCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyNetwork::DisconnectChatControl() completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyDisconnectChatControlCompletedStateChange object for more
    /// information.
    /// </remarks>
    DisconnectChatControlCompleted,

    /// <summary>
    /// The operation started by a previous call to PartyLocalChatControl::PopulateAvailableTextToSpeechProfiles()
    /// completed.
    /// </summary>
    /// <remarks>
    /// The PartyStateChange object should be cast to a PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange
    /// object for more information.
    /// </remarks>
    PopulateAvailableTextToSpeechProfilesCompleted,
};

/// <summary>
/// Reason values indicating whether an operation that results in a completion state change succeeded or why it may have
/// failed.
/// </summary>
enum class PartyStateChangeResult
{
    /// <summary>
    /// The operation succeeded.
    /// </summary>
    Succeeded,

    /// <summary>
    /// An unknown error occurred.
    /// </summary>
    UnknownError,

    /// <summary>
    /// Another title operation canceled this operation.
    /// </summary>
    CanceledByTitle,

    /// <summary>
    /// The local device has internet connectivity issues which caused the operation to fail.
    /// </summary>
    InternetConnectivityError,

    /// <summary>
    /// The operation failed because of an unexpected error in the Party Service.
    /// </summary>
    PartyServiceError,

    /// <summary>
    /// There are no available transparent cloud relay servers in the regions specified by the call to
    /// PartyManager::CreateNewNetwork().
    /// </summary>
    NoServersAvailable,

    /// <summary>
    /// The PartyLocalUser specified in the call to PartyManager::CreateNewNetwork() or
    /// PartyNetwork::AuthenticateLocalUser() is not authorized to complete the operation.
    /// </summary>
    UserNotAuthorized,

    /// <summary>
    /// The PartyLocalUser specified in the call to PartyManager::CreateNewNetwork() has created too many networks and
    /// cannot create new networks at this time.
    /// </summary>
    UserCreateNetworkThrottled,

    /// <summary>
    /// The title has not been enabled to use PlayFab Party. PlayFab Party must be enabled in the PlayFab Game Manager.
    /// </summary>
    TitleNotEnabledForParty,

    /// <summary>
    /// The title has created too many networks.
    /// </summary>
    /// <remarks>
    /// The title scale configuration in the PlayFab Party portal has been reached and will not allow additional
    /// networks to be created.
    /// </remarks>
    TitleCreateNetworkThrottled,

    /// <summary>
    /// The network rejected this operation because it would violate a limit in the network's configuration.
    /// </summary>
    /// <seealso cref="PartyNetworkConfiguration" />
    NetworkLimitReached,

    /// <summary>
    /// The network no longer exists.
    /// </summary>
    NetworkNoLongerExists,

    /// <summary>
    /// The network is not currently allowing new devices or users to join.
    /// </summary>
    NetworkNotJoinable,

    /// <summary>
    /// The operation failed because this version of the Party library was incompatible with either the Party service or
    /// the Party network.
    /// </summary>
    VersionMismatch,

    /// <summary>
    /// The network was gracefully exited by the local device.
    /// </summary>
    LeaveNetworkCalled,
};

/// <summary>
/// The reasons for removing a local user from a network.
/// </summary>
enum class PartyLocalUserRemovedReason
{
    /// <summary>
    /// The local user is being removed because PartyNetwork::AuthenticateLocalUser() asynchronously failed.
    /// </summary>
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    AuthenticationFailed,

    /// <summary>
    /// The local user is being removed because the title called PartyNetwork::RemoveLocalUser().
    /// </summary>
    RemoveLocalUser,

    /// <summary>
    /// The local user is being removed because the title called PartyManager::DestroyLocalUser().
    /// </summary>
    DestroyLocalUser,

    /// <summary>
    /// The local user is being removed because the network is being destroyed.
    /// </summary>
    DestroyNetwork,
};

/// <summary>
/// The reasons an object might be destroyed.
/// </summary>
enum class PartyDestroyedReason
{
    /// <summary>
    /// The invitation|endpoint|device|network|chat control is being destroyed gracefully by request.
    /// </summary>
    Requested,

    /// <summary>
    /// The invitation|endpoint|device|network|chat control is being destroyed because connectivity to the transparent
    /// cloud relay server was lost.
    /// </summary>
    Disconnected,

    /// <summary>
    /// The device|user the invitation|endpoint|chat control depended upon was kicked.
    /// </summary>
    Kicked,

    /// <summary>
    /// No local users on the local device were authenticated on the network, so the local device lost visibility to
    /// the remotely managed invitation|endpoint|device|chat control.
    /// </summary>
    /// <remarks>
    /// Even though the local object referring to the remotely managed object has been destroyed, the remotely managed
    /// object may still exist in the network.
    /// </remarks>
    DeviceLostAuthentication,

    /// <summary>
    /// The invitation|endpoint creation failed asynchronously, so the local object has been destroyed.
    /// </summary>
    CreationFailed,
};

/// <summary>
/// Defines the types of threads that Party library uses for internal purposes.
/// </summary>
/// <seealso cref="PartyManager::GetThreadAffinityMask" />
/// <seealso cref="PartyManager::SetThreadAffinityMask" />
enum class PartyThreadId
{
    /// <summary>
    /// Represents Party library internal audio threads.
    /// </summary>
    /// <remarks>
    /// Party library internal audio threads are high priority, frequently-running threads with real-time requirements.
    /// <para>
    /// On Windows, these audio threads interact directly with XAudio2 every 20-40 milliseconds. The Party library's
    /// instance(s) of XAudio2 will be initialized with a processor affinity that corresponds to the processor affinity
    /// configured for the audio thread type via PartyManager::SetThreadAffinityMask(). If no processor affinity is
    /// specified for the audio thread type, the instance(s) of XAudio2 will be initialized with a processor affinity of
    /// XAUDIO2_DEFAULT_PROCESSOR.
    /// </para>
    /// </remarks>
    Audio,

    /// <summary>
    /// Represents Party library internal networking threads.
    /// </summary>
    /// <remarks>
    /// Party library internal networking threads are driven from both network I/O and polling mechanisms. These wake
    /// every 50 to 100 milliseconds or whenever network traffic is received.
    /// </remarks>
    Networking,
};

/// <summary>
/// The options for sending a message.
/// </summary>
/// <seealso cref="PartySendMessageQueuingConfiguration" />
/// <seealso cref="PartyDataBuffersReturnedStateChange" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
/// <seealso cref="PartyLocalEndpoint::FlushMessages" />
enum class PartySendMessageOptions : int32_t
{
    /// <summary>
    /// Use the default PartySendMessageOptions.
    /// </summary>
    /// <remarks>
    /// The default options are <em>BestEffortDelivery</em>, <em>NonsequentialDelivery</em>, <em>CopyDataBuffers</em>,
    /// <em>CoalesceOpportunistically</em>, and <em>RequireTimelyAcknowledgement</em>.
    /// </remarks>
    Default = 0x0000,

    /// <summary>
    /// Ensure the message is delivered to all targets, retransmitting if necessary.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This option flag guarantees the message will arrive at each target endpoint, regardless of environmental packet
    /// loss, unless the target endpoint is destroyed. Packet transmissions will be retried as needed.
    /// </para>
    /// <para>
    /// This option flag works well when sending important state information that must always reach the destination or
    /// else the target should be removed from the network. Use it with message content that does not have redundancy or
    /// the ability to be interpolated/extrapolated if it's lost, and is worth the potential increased bandwidth usage
    /// should packet retransmissions be needed.
    /// </para>
    /// <para>
    /// Guaranteeing delivery by itself doesn't imply a guarantee of a particular delivery order; use the
    /// <em>SequentialDelivery</em> option flag to enforce ordering.
    /// </para>
    /// </remarks>
    GuaranteedDelivery = 0x0001,

    /// <summary>
    /// Transmit the message best-effort and ignore any packet loss.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This option flag requests only a single attempt to transmit the message. If environmental packet loss occurs,
    /// the transmission will not be retried and the application should be prepared to handle the message's absence.
    /// </para>
    /// <para>
    /// This option flag works well for information that is constantly being updated and doesn't require every update to
    /// arrive. Use it with message content that already has redundancy or the ability to be interpolated/extrapolated
    /// if it's lost and isn't worth extra bandwidth to retransmit.
    /// </para>
    /// <para>
    /// This is the default if the <em>GuaranteedDelivery</em> option flag is not specified.
    /// </para>
    /// </remarks>
    BestEffortDelivery = 0x0000,

    /// <summary>
    /// Deliver the message in order relative to other messages sent from this local endpoint to the target endpoint
    /// that were also sent sequentially.
    /// </summary>
    /// <remarks>
    /// <para>
    /// <em>SequentialDelivery</em> doesn't provide any guarantees about the ordering of messages sent from different
    /// local endpoints and/or to different target endpoints. Each endpoint pairing should be considered a separate
    /// sequence space.
    /// </para>
    /// <para>
    /// No guarantees are made about the order of sequential messages in relation to non-sequential messages.
    /// </para>
    /// <para>
    /// This option flag works well for state information that should reach the destination in a particular sequence,
    /// even if that means slightly less network efficiency and possibly waiting a bit longer to receive it if there is
    /// packet loss or reordering by the environment.
    /// </para>
    /// <para>
    /// Using <em>SequentialDelivery</em> with <em>GuaranteedDelivery</em> may result in messages being queued on the
    /// target endpoint while waiting for previously sent sequential messages to arrive. This may result in a perceived
    /// increase in latency when experiencing environmental packet loss or reordering, but the target endpoint will
    /// always see every message, in the same order in which they were sent.
    /// </para>
    /// <para>
    /// Using <em>SequentialDelivery</em> with <em>BestEffortDelivery</em> may result in messages being dropped if one
    /// arrives at the target endpoint out of order and a later sequential message had already been delivered. The
    /// target endpoint will always see the sequence moving forward, but there may be gaps in that sequence. An older
    /// message will never be delivered after a newer one.
    /// </para>
    /// </remarks>
    SequentialDelivery = 0x0002,

    /// <summary>
    /// Deliver the message to targets as soon as it arrives.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Messages sent with the non-sequential delivery option do not provide any guarantees about the order in which
    /// they are delivered with respect to any other messages, sequential or non-sequential. They will be delivered to
    /// the targets as soon as they arrive, which may not be the same order in which they were sent if there is packet
    /// loss or reordering by the environment.
    /// </para>
    /// <para>
    /// This option flag works well for messages that are safe to process in any order or have their own inherent
    /// ordering information already, and where you'd like maximum network efficiency and lowest perceived latency.
    /// </para>
    /// <para>
    /// This is the default if the <em>SequentialDelivery</em> option flag is not specified.
    /// </para>
    /// </remarks>
    NonsequentialDelivery = 0x0000,

    /// <summary>
    /// Instructs the Party library to make a copy of the supplied data buffers for subsequent transmission.
    /// </summary>
    /// <remarks>
    /// <para>
    /// The memory contents in the provided PartyDataBuffer structures will be copied so the caller does not need to
    /// keep the buffers around after PartyLocalEndpoint::SendMessage() returns. This is more convenient but slightly
    /// less efficient than using the <em>DontCopyDataBuffers</em> option flag.
    /// </para>
    /// <para>
    /// This is the default if the <em>DontCopyDataBuffers</em> option flag is not specified.
    /// </para>
    /// </remarks>
    CopyDataBuffers = 0x0000,

    /// <summary>
    /// Informs the Party library to use the supplied data buffers directly and that the caller will keep the memory
    /// valid until the library no longer needs them.
    /// </summary>
    /// <remarks>
    /// <para>
    /// The memory referenced by the provided PartyDataBuffer structures will not be copied but instead ownership will
    /// temporarily be transferred to the Party library so the memory can be accessed directly without additional
    /// copying overhead during the transmission process. It's the caller's responsibility to ensure the memory buffers
    /// remain valid and unmodified until the library no longer needs them and ownership is transferred back via a
    /// PartyStateChangeType::DataBuffersReturned state change. This is more efficient but can be less convenient than
    /// using the <em>CopyDataBuffers</em> option.
    /// </para>
    /// <para>
    /// The PartyDataBuffer structures themselves do not need to remain valid after the
    /// PartyLocalEndpoint::SendMessage() call returns, only the memory they reference.
    /// </para>
    /// </remarks>
    DontCopyDataBuffers = 0x0004,

    /// <summary>
    /// Specifies that this message should be coalesced with any other queued messages but should not delay transmission
    /// if there aren't any waiting.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Coalescing multiple messages together in a single packet allows maximizing bandwidth efficiency (reducing per-
    /// packet overhead) at the potential expense of perceived latency for a message if you delay its transmission in
    /// order to coalesce. Sending with this flag causes the Party library to coalesce the message if there are other
    /// queued messages available, but not to wait for more messages if none exist and this message can be transmitted
    /// immediately.
    /// </para>
    /// <para>
    /// Use this flag if you typically batch your network updates into single, periodic messages that are not likely to
    /// be queued around the same time as other messages and would not gain bandwidth efficiency if delayed.
    /// </para>
    /// <para>
    /// This flag does not guarantee that the message begins transmitting immediately. If the connection quality or
    /// receiver responsiveness do not appear to currently support sending additional data yet, then the message may be
    /// queued to await the next transmission opportunity.
    /// </para>
    /// <para>
    /// This is the default if the <em>AlwaysCoalesceUntilFlushed</em> option flag is not specified.
    /// </para>
    /// </remarks>
    CoalesceOpportunistically = 0x0000,

    /// <summary>
    /// Specifies that this message should always try to be coalesced with other messages and expect a
    /// PartyLocalEndpoint::FlushMessages() call to begin transmitting.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Coalescing multiple messages together in a single packet allows maximizing bandwidth efficiency (reducing per-
    /// packet overhead) at the potential expense of perceived latency for a message if you delay its transmission in
    /// order to coalesce. Sending with this flag causes the Party library to always prefer coalescing the message and
    /// delay transmission until PartyLocalEndpoint::FlushMessages() is called.
    /// </para>
    /// <para>
    /// Consider using this flag if you typically send a lot of small messages to the same targets in the same update
    /// loop and want to explicitly inform the Party library when the full update loop iteration is complete.
    /// </para>
    /// <para>
    /// Even with this flag there are scenarios where the message might begin transmitting without requiring an explicit
    /// PartyLocalEndpoint::FlushMessages() call. This can occur when there are other queued messages that are already
    /// being transmitted for other reasons and there is room in the packet to include this message. Similarly, when
    /// enough message data bytes exist to send a full packet and no more coalescence is possible, the packet will be
    /// sent. Calling PartyLocalEndpoint::FlushMessages() when all messages have already begun transmitting is benign.
    /// </para>
    /// </remarks>
    AlwaysCoalesceUntilFlushed = 0x0008,

    /// <summary>
    /// Indicates that this message should be acknowledged (if needed) in a timely manner.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Receivers acknowledge reception of messages to inform the sender of delivery success or failure so it can do
    /// things such as retry dropped packets that contained messages sent with the <em>GuaranteedDelivery</em> option
    /// flag. Acknowledgements are often piggybacked on packets as part of typical bi-directional communication, but if
    /// no packets are flowing in the return direction, this flag instructs the target endpoints to only wait a small,
    /// internally managed timeout for piggybacking opportunities before forcing acknowledgement packets to inform the
    /// sender. That dedicated packet consumes some extra overhead but ensures the sender gets timely status for issuing
    /// any necessary retries.
    /// </para>
    /// <para>
    /// Using this flag for most guaranteed delivery messages is recommended. It works well with messages that are
    /// latency sensitive. It also works well when bi-directional guaranteed delivery send patterns are infrequent or
    /// unpredictable.
    /// </para>
    /// <para>
    /// This is the default if the <em>AllowLazyAcknowledgement</em> option flag is not specified.
    /// </para>
    /// <para>
    /// This flag is ignored if the <em>GuaranteedDelivery</em> option flag is not specified.
    /// </para>
    /// </remarks>
    RequireTimelyAcknowledgement = 0x0000,

    /// <summary>
    /// Indicates that this message can be acknowledged when convenient rather than urgently.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Receivers acknowledge reception of messages to inform the sender of delivery success or failure so it can do
    /// things such as retry dropped packets that contained messages sent with the <em>GuaranteedDelivery</em> option
    /// flag. Acknowledgements are often piggybacked on packets as part of typical bi-directional communication, but if
    /// no packets are flowing in the return direction, this flag instructs the target endpoints to wait for
    /// piggybacking opportunities without forcing acknowledgement packets to inform the sender. This delays the sender
    /// finding out status for any necessary retries, but avoids extra overhead consumed by a dedicated packet.
    /// </para>
    /// <para>
    /// Consider using this flag for guaranteed delivery messages that are "fire-and-forget" and are not latency
    /// sensitive. It may also reduce overhead when bi-directional send patterns are frequent.
    /// </para>
    /// <para>
    /// This flag is ignored if the <em>GuaranteedDelivery</em> option flag is not also specified.
    /// </para>
    /// </remarks>
    AllowLazyAcknowledgement = 0x0010,
};

DEFINE_ENUM_FLAG_OPERATORS(PartySendMessageOptions);

/// <summary>
/// Option flags describing a message that was received.
/// </summary>
/// <seealso cref="PartyEndpointMessageReceivedStateChange" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
enum class PartyMessageReceivedOptions : int32_t
{
    /// <summary>
    /// There is no additional message reception information.
    /// </summary>
    None = 0x0000,

    /// <summary>
    /// The message's delivery was guaranteed.
    /// </summary>
    /// <remarks>
    /// This flag's presence or absence represents the actual delivery mode. The Party library may occasionally adjust
    /// messages internally to use guaranteed delivery even if PartySendMessageOptions::GuaranteedDelivery was not
    /// originally specified to PartyLocalEndpoint::SendMessage(). It will never disable guaranteed delivery if it had
    /// originally been requested, however.
    /// </remarks>
    GuaranteedDelivery = 0x0001,

    /// <summary>
    /// The message was delivered using sequencing information.
    /// </summary>
    /// <remarks>
    /// This flag's presence or absence represents the actual delivery mode. The Party library may occasionally adjust
    /// messages internally to sequential delivery even if PartySendMessageOptions::SequentialDelivery was not
    /// originally specified to PartyLocalEndpoint::SendMessage(). It will never disable sequential delivery if it had
    /// originally been requested, however.
    /// </remarks>
    SequentialDelivery = 0x0002,

    /// <summary>
    /// The message was larger than could fit in available space in a single packet and needed to be split across
    /// multiple packets for delivery.
    /// </summary>
    /// <remarks>
    /// The Party library automatically fragments and reassembles large messages that exceed the maximum size supported
    /// by the environment so that callers are not required to manage this. However, there is a small amount of overhead
    /// associated with fragmentation. Callers that are able to send smaller messages or otherwise naturally break up
    /// large state payloads efficiently themselves may wish to do so.
    /// </remarks>
    RequiredFragmentation = 0x0004,
};

DEFINE_ENUM_FLAG_OPERATORS(PartyMessageReceivedOptions);

/// <summary>
/// The type of expression PartyLocalEndpoint::CancelMessages() should evaluate in order to match queued messages.
/// </summary>
/// <seealso cref="PartySendMessageQueuingConfiguration" />
/// <seealso cref="PartyLocalEndpoint::CancelMessages" />
enum class PartyCancelMessagesFilterExpression
{
    /// <summary>
    /// Cancels all messages regardless of identity.
    /// </summary>
    /// <remarks>
    /// The PartyLocalEndpoint::CancelMessages() <em>messageIdentityFilterMask</em> and
    /// <em>filteredMessageIdentitiesToMatch</em> parameters and messages' PartySendMessageQueuingConfiguration
    /// structure <em>identityForCancelFilters</em> field are ignored for this expression type.
    /// </remarks>
    None,

    /// <summary>
    /// Cancels messages where the filter expression <c>(<em>identityForCancelFilters</em> &
    /// <em>messageIdentityFilterMask</em>) == <em>filteredMessageIdentitiesToMatch</em></c> evaluates to true.
    /// </summary>
    /// <remarks>
    /// <para>
    /// To filter to messages that have PartySendMessageQueuingConfiguration structure <em>identityForCancelFilters</em>
    /// field values with a particular bit (or bits) set a particular way, specify a
    /// PartyLocalEndpoint::CancelMessages() <em>messageIdentityFilterMask</em> parameter with the bits to check enabled
    /// and the desired way those bits must be set for a match in the <em>filteredMessageIdentitiesToMatch</em>
    /// parameter value.
    /// </para>
    /// <para>
    /// For example, to require matching specific <em>identityForCancelFilters</em> field values exactly, specify a
    /// <em>messageIdentityFilterMask</em> parameter with all bits set (the maximum uint32_t value) and the required
    /// value in the <em>filteredMessageIdentitiesToMatch</em> parameter.
    /// </para>
    /// <para>
    /// Alternatively, to filter to messages that have <em>identityForCancelFilters</em> values where no bits from a
    /// particular group are enabled, specify a <em>messageIdentityFilterMask</em> parameter with the relevant bits to
    /// check and a value of zero for the <em>filteredMessageIdentitiesToMatch</em> parameter.
    /// </para>
    /// </remarks>
    IdentityAndMaskEqualsMatchValue,

    /// <summary>
    /// Cancels messages where the filter expression <c>(<em>identityForCancelFilters</em> &
    /// <em>messageIdentityFilterMask</em>) != <em>filteredMessageIdentitiesToMatch</em></c> evaluates to true.
    /// </summary>
    /// <remarks>
    /// <para>
    /// To filter to messages that do not have PartySendMessageQueuingConfiguration structure
    /// <em>identityForCancelFilters</em> field values with a particular bit (or bits) set a specific way, provide a
    /// PartyLocalEndpoint::CancelMessages() <em>messageIdentityFilterMask</em> parameter with the bits to check enabled
    /// and the desired way those bits must not be set for a match in the <em>filteredMessageIdentitiesToMatch</em>
    /// parameter value.
    /// </para>
    /// <para>
    /// For example, to filter to messages that have <em>identityForCancelFilters</em> values with a particular bit (or
    /// at least one bit from a particular group) enabled, specify a <em>messageIdentityFilterMask</em> parameter with
    /// the relevant bits to check and a value of zero for the <em>filteredMessageIdentitiesToMatch</em> parameter.
    /// </para>
    /// <para>
    /// Alternatively, to exclude specific <em>identityForCancelFilters</em> field values exactly, specify a
    /// <em>messageIdentityFilterMask</em> parameter with all bits set (the maximum uint32_t value) and the excluded
    /// value in the <em>filteredMessageIdentitiesToMatch</em> parameter.
    /// </para>
    /// </remarks>
    IdentityAndMaskDoesNotEqualMatchValue,
};

/// <summary>
/// The options for synchronizing messages between endpoints.
/// </summary>
enum class PartySynchronizeMessagesBetweenEndpointsOptions : int32_t
{
    /// <summary>
    /// No additional options.
    /// </summary>
    None = 0x0000,

    /// <summary>
    /// Synchronize messages with the specified endpoints and all shared properties.
    /// </summary>
    SynchronizeMessagesWithSharedProperties = 0x0001,
};

DEFINE_ENUM_FLAG_OPERATORS(PartySynchronizeMessagesBetweenEndpointsOptions);

/// <summary>
/// The performance counters, queue lengths, historical usage metrics, or other statistical information that can be
/// retrieved for a network.
/// </summary>
/// <seealso cref="PartyEndpointStatistic" />
/// <seealso cref="PartySendMessageOptions" />
/// <seealso cref="PartyNetwork::GetNetworkStatistics" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
/// <seealso cref="PartyLocalEndpoint::CancelMessages" />
enum class PartyNetworkStatistic
{
    /// <summary>
    /// The current moving average round trip latency ("ping time") in milliseconds to the network's cloud relay server.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This latency represents a moving average of the time it currently takes for this local device to send a message
    /// and receive a response from the transparent cloud relay server.
    /// </para>
    /// </remarks>
    AverageRelayServerRoundTripLatencyInMilliseconds,

    /// <summary>
    /// The total number of internal protocol packets ever transmitted to remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of internal protocol packets transmitted by the local device for any
    /// network reason. It includes packets generated as a result of PartyLocalEndpoint::SendMessage() calls but doesn't
    /// necessarily have a one-to-one correspondence with them because multiple small messages may be coalesced together
    /// into a single packet, or a large message may be fragmented into multiple packets depending on configuration and
    /// environmental factors. Further, packets may be used to carry chat or other internal library functionality (e.g.,
    /// API operation support messages, protocol acknowledgements or retries) on behalf of the application without an
    /// explicit PartyLocalEndpoint::SendMessage() call.
    /// </para>
    /// <para>
    /// This statistic does not include any packets generated for HTTP web client operations that are used internally by
    /// the Party library for some aspects of authentication, management transactions, speech-to-text transcription, and
    /// text-to-speech synthesis.
    /// </para>
    /// </remarks>
    SentProtocolPackets,

    /// <summary>
    /// The total number of internal protocol bytes ever transmitted to remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of bytes in internal protocol packets transmitted by the local device
    /// for any network reason. This size includes PartyLocalEndpoint::SendMessage() payloads but also their internal
    /// protocol overhead, as well as any chat or other internal library functionality needed (e.g., API operation
    /// support messages, protocol acknowledgements or retries) on behalf of the application without an explicit
    /// PartyLocalEndpoint::SendMessage() call.
    /// </para>
    /// <para>
    /// The reported value does not include the packet overhead for Internet protocols (e.g., UDP, IP) or that of lower
    /// level media over which the Party library internal protocol operates.
    /// </para>
    /// <para>
    /// This statistic does not include the sizes of any packets generated for HTTP web client operations that are used
    /// internally by the Party library for some aspects of authentication, management transactions, speech-to-text
    /// transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    SentProtocolBytes,

    /// <summary>
    /// The total number of internal protocol packets ever re-transmitted to remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of internal protocol packet retransmissions by the local device due
    /// to apparent environmental loss of an earlier attempt. The Party library will only retry lost packets that
    /// contain application messages sent with PartySendMessageOptions::GuaranteedDelivery or internal library messages
    /// with similar delivery requirements.
    /// </para>
    /// <para>
    /// This statistic does not include any retries of packets generated for HTTP web client operations that are used
    /// internally by the Party library for some aspects of authentication, management transactions, speech-to-text
    /// transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    RetriedProtocolPackets,

    /// <summary>
    /// The total number of internal protocol bytes ever re-transmitted to remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of bytes in internal protocol packet retransmissions by the local
    /// device due to apparent environmental loss of an earlier attempt. This size includes payloads of application
    /// messages sent with PartySendMessageOptions::GuaranteedDelivery or internal library messages with similar
    /// delivery requirements.
    /// </para>
    /// <para>
    /// The reported value does not include the retried packet overhead for Internet protocols (e.g., UDP, IP) or that
    /// of lower level media over which the Party library internal protocol operates.
    /// </para>
    /// <para>
    /// This statistic does not include the sizes of any retried packets generated for HTTP web client operations that
    /// are used internally by the Party library for some aspects of authentication, management transactions,
    /// speech-to-text transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    RetriedProtocolBytes,

    /// <summary>
    /// The total number of internal protocol packets to remote devices in this network that are believed to have been
    /// dropped.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of internal protocol packet transmissions by the local device that
    /// were attempted but appeared to suffer environmental loss. They may or may not have been retried (see
    /// <em>RetriedProtocolPackets</em>).
    /// </para>
    /// <para>
    /// This statistic does not include any dropped packets that were generated for HTTP web client operations used
    /// internally by the Party library for some aspects of authentication, management transactions, speech-to-text
    /// transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    DroppedProtocolPackets,

    /// <summary>
    /// The total number of internal protocol packets ever received from remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of internal protocol packets received by the local device for any
    /// network reason, which does not have a one-to-one correspondence with
    /// PartyStateChangeType::EndpointMessageReceived state changes. Multiple small messages may be coalesced together
    /// into a single packet, or a large message may be fragmented into multiple packets depending on configuration and
    /// environmental factors. Further, packets may be used to carry chat or other internal library functionality (e.g.,
    /// API operation support messages, protocol acknowledgements or retries) on behalf of the application without an
    /// explicit PartyLocalEndpoint::SendMessage() call.
    /// </para>
    /// <para>
    /// This statistic does not include any packets received as part of HTTP web client operations that are used
    /// internally by the Party library for some aspects of authentication, management transactions, speech-to-text
    /// transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    ReceivedProtocolPackets,

    /// <summary>
    /// The total number of internal protocol bytes ever received from remote devices as part of this network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This statistic represents the total number of bytes in internal protocol packets received by the local device
    /// for any network reason. This size includes PartyStateChangeType::EndpointMessageReceived state change payloads
    /// but also their internal protocol overhead, as well as any chat or other internal library functionality needed
    /// (e.g., API operation support messages, protocol acknowledgements or retries).
    /// </para>
    /// <para>
    /// The reported value does not include the packet overhead for Internet protocols (e.g., UDP, IP) or that of lower
    /// level media over which the Party library internal protocol operates.
    /// </para>
    /// <para>
    /// This statistic does not include the sizes of any packets received as part of HTTP web client operations that are
    /// used internally by the Party library for some aspects of authentication, management transactions, speech-to-text
    /// transcription, and text-to-speech synthesis.
    /// </para>
    /// </remarks>
    ReceivedProtocolBytes,

    /// <summary>
    /// The number of messages currently queued by PartyLocalEndpoint::SendMessage() but not yet transmitted from all
    /// local endpoints to all remote endpoints in the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages will only be counted a single
    /// time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyQueuedSendMessages,

    /// <summary>
    /// The number of bytes of data in messages currently queued by PartyLocalEndpoint::SendMessage() but not yet
    /// transmitted from all local endpoints to all remote endpoints in the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages' bytes will only be counted a
    /// single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyQueuedSendMessageBytes,

    /// <summary>
    /// The number of PartyLocalEndpoint::SendMessage() messages from all local endpoints to all remote endpoints in the
    /// network that are currently being transmitted or still have more local state changes to be processed.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message is considered "active" as soon as its first byte has been placed in a packet that is being
    /// transmitted. It remains active until transmission completes and the local
    /// PartyStateChangeType::DataBuffersReturned state change for it (if applicable) has been returned with
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages will only be counted a single
    /// time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyActiveSendMessages,

    /// <summary>
    /// The number of bytes of data in PartyLocalEndpoint::SendMessage() messages from all local endpoints to all remote
    /// endpoints in the network that are currently being transmitted or still have more local state changes to be
    /// processed.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message is considered "active" as soon as its first byte has been placed in a packet that is being
    /// transmitted. It remains active until transmission completes and the local
    /// PartyStateChangeType::DataBuffersReturned state change for it (if applicable) has been returned with
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages' bytes will only be counted a
    /// single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyActiveSendMessageBytes,

    /// <summary>
    /// The total number of PartyLocalEndpoint::SendMessage() messages from all local endpoints to all remote endpoints
    /// in the network that were ever discarded for exceeding their send queue timeouts without being transmitted.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message's send queue timeout is specified using the PartySendMessageQueuingConfiguration structure
    /// <em>timeoutInMillseconds</em> field when calling PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages will only be counted a single
    /// time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// Note that only local and remote endpoints that currently exist will be included when querying this statistic.
    /// When endpoints that had timed out messages get destroyed between queries, this statistic might be perceived as
    /// "going backward".
    /// </para>
    /// </remarks>
    TimedOutSendMessages,

    /// <summary>
    /// The total number of bytes of data in PartyLocalEndpoint::SendMessage() messages from all local endpoints to all
    /// remote endpoints in the network that were ever discarded for exceeding their send queue timeouts without being
    /// transmitted.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message's send queue timeout is specified using the PartySendMessageQueuingConfiguration structure
    /// <em>timeoutInMillseconds</em> field when calling PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages' bytes will only be counted a
    /// single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// Note that only local and remote endpoints that currently exist will be included when querying this statistic.
    /// When endpoints that had timed out messages get destroyed between queries, this statistic might be perceived as
    /// "going backward".
    /// </para>
    /// </remarks>
    TimedOutSendMessageBytes,

    /// <summary>
    /// The total number of PartyLocalEndpoint::SendMessage() messages from all local endpoints to all remote endpoints
    /// in the network that were ever canceled.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Messages are canceled before being transmitted by the application calling PartyLocalEndpoint::CancelMessages()
    /// with a matching filter expression.
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages will only be counted a single
    /// time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// Note that only local and remote endpoints that currently exist will be included when querying this statistic.
    /// When endpoints that had canceled messages get destroyed between queries, this statistic might be perceived as
    /// "going backward".
    /// </para>
    /// </remarks>
    CanceledSendMessages,

    /// <summary>
    /// The total number of bytes of data in PartyLocalEndpoint::SendMessage() messages from all local endpoints to all
    /// remote endpoints in the network that were ever canceled.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Messages are canceled before being transmitted by the application calling PartyLocalEndpoint::CancelMessages()
    /// with a matching filter expression.
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. Such messages' bytes will only be counted a
    /// single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// Note that only local and remote endpoints that currently exist will be included when querying this statistic.
    /// When endpoints that had canceled messages get destroyed between queries, this statistic might be perceived as
    /// "going backward".
    /// </para>
    /// </remarks>
    CanceledSendMessageBytes,
};

/// <summary>
/// The performance counters, queue lengths, historical usage metrics, or other statistical information that can be
/// retrieved for an endpoint.
/// </summary>
/// <seealso cref="PartyNetworkStatistic" />
/// <seealso cref="PartySendMessageQueuingConfiguration" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
/// <seealso cref="PartyLocalEndpoint::CancelMessages" />
/// <seealso cref="PartyLocalEndpoint::GetEndpointStatistics" />
enum class PartyEndpointStatistic
{
    /// <summary>
    /// The number of messages currently queued by PartyLocalEndpoint::SendMessage() but not yet transmitted from the
    /// local endpoint to the specified target endpoints.
    /// </summary>
    /// <remarks>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyQueuedSendMessages,

    /// <summary>
    /// The number of bytes of data in messages currently queued by PartyLocalEndpoint::SendMessage() but not yet
    /// transmitted from the local endpoint to the specified target endpoints.
    /// </summary>
    /// <remarks>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message bytes will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyQueuedSendMessageBytes,

    /// <summary>
    /// The number of PartyLocalEndpoint::SendMessage() messages from the local endpoint to the specified target
    /// endpoints that are currently being transmitted or still have more local state changes to be processed.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message is considered "active" as soon as its first byte has been placed in a packet that is being
    /// transmitted. It remains active until transmission completes and the local
    /// PartyStateChangeType::DataBuffersReturned state change for it (if applicable) has been returned with
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is tracked per PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyActiveSendMessages,

    /// <summary>
    /// The number of bytes of data in PartyLocalEndpoint::SendMessage() messages from the local endpoint to the
    /// specified target endpoints that are currently being transmitted or still have more local state changes to be
    /// processed.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message is considered "active" as soon as its first byte has been placed in a packet that is being
    /// transmitted. It remains active until transmission completes and the local
    /// PartyStateChangeType::DataBuffersReturned state change for it (if applicable) has been returned with
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is tracked per PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message bytes will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// </remarks>
    CurrentlyActiveSendMessageBytes,

    /// <summary>
    /// The total number of PartyLocalEndpoint::SendMessage() messages from the local endpoint to the specified target
    /// endpoints that were ever discarded for exceeding their send queue timeouts without being transmitted.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message's send queue timeout is specified using the PartySendMessageQueuingConfiguration structure
    /// <em>timeoutInMillseconds</em> field when calling PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// When querying this statistic for all target endpoints by providing a zero-entry array to
    /// PartyLocalEndpoint::GetEndpointStatistics(), note that only endpoints that currently exist will be included. If
    /// an endpoint that had timed out messages gets destroyed between queries, this count might be perceived as "going
    /// backward".
    /// </para>
    /// </remarks>
    TimedOutSendMessages,

    /// <summary>
    /// The total number of bytes of data in PartyLocalEndpoint::SendMessage() messages from the local endpoint to the
    /// specified target endpoints that were ever discarded for exceeding their send queue timeouts without being
    /// transmitted.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A message's send queue timeout is specified using the PartySendMessageQueuingConfiguration structure
    /// <em>timeoutInMillseconds</em> field when calling PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the transparent cloud relay server. If two or more of those endpoints are specified
    /// to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message bytes will only be
    /// counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// When querying this statistic for all target endpoints by providing a zero-entry array to
    /// PartyLocalEndpoint::GetEndpointStatistics(), note that only endpoints that currently exist will be included. If
    /// an endpoint that had timed out messages gets destroyed between queries, this count might be perceived as "going
    /// backward".
    /// </para>
    /// </remarks>
    TimedOutSendMessageBytes,

    /// <summary>
    /// The total number of PartyLocalEndpoint::SendMessage() messages from the local endpoint to the specified target
    /// endpoints that were ever canceled.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Messages are canceled before being transmitted by the application calling PartyLocalEndpoint::CancelMessages()
    /// with a matching filter expression.
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the PartyNetwork transparent cloud relay server. If two or more of those endpoints
    /// are specified to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message will
    /// only be counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// When querying this statistic for all target endpoints by providing a zero-entry array to
    /// PartyLocalEndpoint::GetEndpointStatistics(), note that only endpoints that currently exist will be included. If
    /// an endpoint that had canceled messages gets destroyed between queries, this count might be perceived as "going
    /// backward".
    /// </para>
    /// </remarks>
    CanceledSendMessages,

    /// <summary>
    /// The total number of bytes of data in PartyLocalEndpoint::SendMessage() messages from the local endpoint to the
    /// specified target endpoints that were ever canceled.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Messages are canceled before being transmitted by the application calling PartyLocalEndpoint::CancelMessages()
    /// with a matching filter expression.
    /// </para>
    /// <para>
    /// For efficiency, only a single message is queued by PartyLocalEndpoint::SendMessage() when sending to multiple
    /// target endpoints at once via the PartyNetwork transparent cloud relay server. If two or more of those endpoints
    /// are specified to PartyLocalEndpoint::GetEndpointStatistics() when querying for this statistic, the message bytes
    /// will only be counted a single time rather than multiplied per target endpoint.
    /// </para>
    /// <para>
    /// When querying this statistic for all target endpoints by providing a zero-entry array to
    /// PartyLocalEndpoint::GetEndpointStatistics(), note that only endpoints that currently exist will be included. If
    /// an endpoint that had canceled messages gets destroyed between queries, this count might be perceived as "going
    /// backward".
    /// </para>
    /// </remarks>
    CanceledSendMessageBytes,
};

/// <summary>
/// Defines who may revoke PartyInvitations via PartyNetwork::RevokeInvitation().
/// </summary>
/// <seealso cref="PartyNetwork::RevokeInvitation" />
enum class PartyInvitationRevocability
{
    /// <summary>
    /// The invitation may only be revoked by the PartyLocalUser that created the invitation.
    /// </summary>
    /// <seealso cref="PartyLocalUser" />
    Creator,

    /// <summary>
    /// The invitation may be revoked by any authenticated user in the network.
    /// </summary>
    Anyone,
};

/// <summary>
/// Defines the options for defining the communication relationship between two chat controls.
/// </summary>
enum class PartyChatPermissionOptions
{
    /// <summary>
    /// No chat communication between the local PartyChatControl and the target PartyChatControl is allowed.
    /// </summary>
    None = 0x0,

    /// <summary>
    /// Audio communication from the local PartyChatControl to the target PartyChatControl is allowed.
    /// </summary>
    SendAudio = 0x1,

    /// <summary>
    /// Audio communication from the target PartyChatControl to the local PartyChatControl is allowed.
    /// </summary>
    ReceiveAudio = 0x2,

    /// <summary>
    /// Text communication from the target PartyChatControl to the local PartyChatControl is allowed.
    /// </summary>
    ReceiveText = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(PartyChatPermissionOptions);

/// <summary>
/// Defines the possible options for selecting audio devices
/// </summary>
enum class PartyAudioDeviceSelectionType
{
    /// <summary>
    /// Indicate that no audio device should be used.
    /// </summary>
    None,

    /// <summary>
    /// Select audio device based on the platform settings.
    /// </summary>
    /// <remarks>
    /// If this selection type is used for PartyLocalChatControl::SetAudioInput() or
    /// PartyLocalChatControl::SetAudioOutput() then the audioDeviceSelectionContext should be a nullptr.
    /// </remarks>
    /// <seealso cref="PartyLocalChatControl::SetAudioInput" />
    /// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
    SystemDefault,

    /// <summary>
    /// Select audio device based on the platform and user settings.
    /// </summary>
    /// <remarks>
    /// If this selection type is used for PartyLocalChatControl::SetAudioInput() or
    /// PartyLocalChatControl::SetAudioOutput() then the audioDeviceSelectionContext must be a platform specific user
    /// context.
    /// </remarks>
    /// <seealso cref="PartyLocalChatControl::SetAudioInput" />
    /// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
    PlatformUserDefault,

    /// <summary>
    /// Audio device specified by the game.
    /// <remarks>
    /// If this selection type is used for PartyLocalChatControl::SetAudioInput() or
    /// PartyLocalChatControl::SetAudioOutput() then the audioDeviceSelectionContext must be the identifier of the audio
    /// device to use.
    /// </remarks>
    /// <seealso cref="PartyLocalChatControl::SetAudioInput" />
    /// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
    Manual,
};

/// <summary>
/// Defines the possible states of an audio input associated with a local chat control.
/// </summary>
enum class PartyAudioInputState
{
    /// <summary>
    /// No audio input was specified.
    /// </summary>
    NoInput,

    /// <summary>
    /// The audio input was successfully initialized.
    /// </summary>
    Initialized,

    /// <summary>
    /// The audio input wasn't found.
    /// </summary>
    /// <remarks>
    /// This can occur if the input was removed while in use.
    /// <para>
    /// When in this state, the chat control will subscribe to audio device changes and use the specified input if it
    /// can be found at a later time.
    /// </para>
    /// </remarks>
    NotFound,

    /// <summary>
    /// The user didn't give permission to access the input.
    /// </summary>
    UserConsentDenied,

    /// <summary>
    /// The input doesn't provide a supported format.
    /// </summary>
    UnsupportedFormat,

    /// <summary>
    /// The audio input device is already in use by another chat control.
    /// </summary>
    AlreadyInUse,

    /// <summary>
    /// Initializing the input resulted in an unknown error.
    /// </summary>
    UnknownError,
};

/// <summary>
/// Defines the possible states of an audio output associated with a local chat control.
/// </summary>
enum class PartyAudioOutputState
{
    /// <summary>
    /// No audio output was specified.
    /// </summary>
    NoOutput,

    /// <summary>
    /// The audio output was successfully initialized.
    /// </summary>
    Initialized,

    /// <summary>
    /// The audio output wasn't found.
    /// </summary>
    /// <remarks>
    /// This can occur if the output was removed while in use.
    /// <para>
    /// When in this state, the chat control will subscribe to audio device changes and use the specified output if it
    /// can be found at a later time.
    /// </para>
    /// </remarks>
    NotFound,

    /// <summary>
    /// The output doesn't provide a supported sample rate.
    /// </summary>
    UnsupportedFormat,

    /// <summary>
    /// The audio output device is already in use by another chat control.
    /// </summary>
    AlreadyInUse,

    /// <summary>
    /// Initializing the output resulted in an unknown error.
    /// </summary>
    UnknownError,
};

/// <summary>
/// Defines the possible audio states for a local chat control.
/// </summary>
enum class PartyLocalChatControlChatIndicator
{
    /// <summary>
    /// The local chat control is not generating voice audio.
    /// </summary>
    Silent,

    /// <summary>
    /// The local chat control is generating voice audio.
    /// </summary>
    Talking,

    /// <summary>
    /// The local chat control's audio input is muted.
    /// </summary>
    AudioInputMuted,

    /// <summary>
    /// Either no audio input has been specified for the local chat control, or initializing the specified input failed.
    /// </summary>
    /// <remarks>
    /// This may be due to the user removing a physical audio device, or an error during audio device initialization. A
    /// state change of type LocalChatAudioInputChanged or LocalChatAudioOutputChanged with more granular information
    /// will have been provided prior to the chat indicator changing to this value.
    /// </remarks>
    NoAudioInput,
};

/// <summary>
/// Defines the possible audio states for a target chat control in relation to a local chat control.
/// </summary>
enum class PartyChatControlChatIndicator
{
    /// <summary>
    /// The target chat control isn't generating voice audio.
    /// </summary>
    Silent,

    /// <summary>
    /// The target chat control is generating voice audio.
    /// </summary>
    Talking,

    /// <summary>
    /// The local chat control is not configured to receive audio from the target chat control.
    /// </summary>
    IncomingVoiceDisabled,

    /// <summary>
    /// The target chat control has been muted by the local chat control.
    /// </summary>
    IncomingCommunicationsMuted,
};

/// <summary>
/// Defines the supported genders for PartyTextToSpeechProfiles.
/// </summary>
enum class PartyGender
{
    /// <summary>
    /// The text to speech profile represents a gender-neutral voice.
    /// </summary>
    Neutral,

    /// <summary>
    /// The text to speech profile represents a female voice.
    /// </summary>
    Female,

    /// <summary>
    /// The text to speech profile represents a male voice.
    /// </summary>
    Male,
};

/// <summary>
/// Defines types of transcriptions for PartyVoiceChatTranscriptionReceivedStateChange.
/// </summary>
/// <seealso cref="PartyVoiceChatTranscriptionReceivedStateChange" />
enum class PartyVoiceChatTranscriptionPhraseType
{
    /// <summary>
    /// The transcription is a hypothesis phrase.
    /// </summary>
    /// <remarks>
    /// A hypothesis phrase represents a snapshot into the transcription process and does not represent a stable
    /// accumulation of transcription. For example, a first speech hypothesis may contain the words "fine fun" and the
    /// second hypothesis may contain the words "find funny". Hypothesis messages are frequent and there can be many
    /// hypothesis messages associated with a particular phrase. Once a transcription of type Final is received, no more
    /// hypothesis messages associated with that phrase will be provided; new hypothesis phrases will represent a new
    /// logical phrase. Because each phrase is tied to a speaker, hypothesis messages for a phrase can be correlated by
    /// inspecting the <em>speaker</em> field of the PartyVoiceChatTranscriptionReceivedStateChange.
    /// <para>
    /// Hypothesis phrases can optionally be used to improve the user experience by improving perceived responsiveness.
    /// An example implementation might have a special text box for hypothesis messages that is frequently updated with
    /// the latest hypothesis transcription from each chat control. Once a non-hypothesis transcription is received, the
    /// transcription for the chat control would be removed from the hypothesis text box and rendered in a long-lived
    /// text box.
    /// </para>
    /// </remarks>
    Hypothesis,

    /// <summary>
    /// The transcription is a final phrase.
    /// </summary>
    /// <remarks>
    /// A final phrase represents the end of the transcription process after the speaker has completed a sentence or
    /// phrase. Capitalization, punctuation, inverse text normalization, and profanity masking will have been applied to
    /// this transcription. For example, if a user speaks a phrase represented by the words "my flight to seattle leaves
    /// at six", the transcription will read "My flight to Seattle leaves at 6." Inverse text normalization is the
    /// process that converts the word "six" to the number "6". Profane words will be replaced by asterisks.
    /// <para>
    /// If the associated transcription represents the audio generated by a call to
    /// PartyLocalChatControl::SynthesizeTextToSpeech(), the text string used to generated the audio will be used the
    /// transcription. No post-processing, such as capitalization and punctuation, will be applied to the text.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyLocalChatControl::SynthesizeTextToSpeech" />
    Final,
};

/// <summary>
/// Defines transcription options.
/// </summary>
/// <seealso cref="PartyLocalChatControl::SetTranscriptionOptions" />
enum class PartyVoiceChatTranscriptionOptions
{
    /// <summary>
    /// No chat controls will be transcribed.
    /// </summary>
    None = 0x0,

    /// <summary>
    /// Transcriptions of the local chat control will be generated and provided to the same local chat control via
    /// PartyVoiceChatTranscriptionReceivedStateChange events.
    /// </summary>
    /// <seealso cref="PartyVoiceChatTranscriptionReceivedStateChange" />
    TranscribeSelf = 0x1,

    /// <summary>
    /// Transcriptions of other chat controls with the same language as the local chat control will be generated and
    /// provided to the local chat control via PartyVoiceChatTranscriptionReceivedStateChange events.
    /// </summary>
    /// <seealso cref="PartyVoiceChatTranscriptionReceivedStateChange" />
    TranscribeOtherChatControlsWithMatchingLanguages = 0x2,

    /// <summary>
    /// Transcriptions of other chat controls with languages that are different from the local chat control's language
    /// will be generated and provided to the local chat control via PartyVoiceChatTranscriptionReceivedStateChange
    /// events.
    /// </summary>
    /// <remarks>
    /// The transcriptions are not translated by default. Translation to the local chat control's language can also be
    /// enabled by adding PartyVoiceChatTranscriptionOptions::TranslateToLocalLanguage.
    /// </remarks>
    /// <seealso cref="PartyVoiceChatTranscriptionReceivedStateChange" />
    TranscribeOtherChatControlsWithNonMatchingLanguages = 0x4,

    /// <summary>
    /// Hypothesis phrases will be disabled.
    /// </summary>
    /// <remarks>
    /// Use of hypothesis phrases is encouraged as a best practice to minimize the perceived latency of the
    /// transcription. If the phrases will not be used, however, they can be disabled in order to reduce the network
    /// bandwidth used to send the phrases to the local chat control.
    /// <para>
    /// This option will have no effect unless also combined with PartyVoiceChatTranscriptionOptions::TranscribeSelf,
    /// PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithMatchingLanguages, and/or
    /// PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithNonMatchingLanguages.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyVoiceChatTranscriptionPhraseType" />
    DisableHypothesisPhrases = 0x8,

    /// <summary>
    /// Transcriptions will be translated to the local chat control's language.
    /// </summary>
    /// <remarks>
    /// Transcriptions generated as specified via other PartyVoiceChatTranscriptionOptions values will be translated
    /// into the local chat control's language, which is specified by PartyLocalChatControl::GetLanguage(). The
    /// translations will be provided in addition to the original transcription via
    /// PartyVoiceChatTranscriptionReceivedStateChange events.
    /// <para>
    /// If translation is enabled, a translation corresponding to the local chat control's language will always be
    /// provided in each resulting PartyVoiceChatTranscriptionReceivedStateChange. If the speaking chat control's
    /// language is the same as the local chat control's language, the transcription and translation strings will be
    /// identical.
    /// </para>
    /// <para>
    /// This option will have no effect unless also combined with one or more of
    /// PartyVoiceChatTranscriptionOptions::TranscribeSelf,
    /// PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithMatchingLanguages, and
    /// PartyVoiceChatTranscriptionOptions::TranscribeOtherChatControlsWithNonMatchingLanguages.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyVoiceChatTranscriptionReceivedStateChange" />
    TranslateToLocalLanguage = 0x10,
};

DEFINE_ENUM_FLAG_OPERATORS(PartyVoiceChatTranscriptionOptions);

/// <summary>
/// Defines text chat options.
/// </summary>
/// <seealso cref="PartyLocalChatControl::SetTextChatOptions" />
enum class PartyTextChatOptions
{
    /// <summary>
    /// No options are selected.
    /// </summary>
    None = 0x0,

    /// <summary>
    /// Incoming text chat will be translated to the local chat control's language.
    /// </summary>
    /// <remarks>
    /// The language specified via PartyLocalChatControl::GetLanguage() is the language to which the incoming text
    /// chat will be translated. The translations will be provided in addition to the original text chat via a
    /// PartyChatTextReceivedStateChange.
    /// <para>
    /// If translation is enabled, a translation corresponding to the local chat control's language will always be
    /// provided in each resulting PartyChatTextReceivedStateChange. If the source chat control's language is the
    /// same as the local chat control's language, the chat text and translation strings will be identical.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyChatTextReceivedStateChange" />
    TranslateToLocalLanguage = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(PartyTextChatOptions);

/// <summary>
/// Option flags describing a translation that was received.
/// </summary>
enum class PartyTranslationReceivedOptions
{
    /// <summary>
    /// There is no additional translation information.
    /// </summary>
    None = 0x0,

    /// <summary>
    /// The translation was truncated.
    /// </summary>
    /// <remarks>
    /// A translation string may be up to <see cref="c_maxChatTextMessageLength" /> characters long, not including the
    /// null terminator. Truncation occurs if the translated string length would exceed that limit, which can happen
    /// due to language differences even though the original string length is less than or equal to <see
    /// cref="c_maxChatTextMessageLength" />. Truncation may occur at an arbitrary point in the UTF-8 byte sequence
    /// and may not result in a complete, valid character or word. Strings are always null terminated, even when
    /// truncated.
    /// </remarks>
    Truncated = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(PartyTranslationReceivedOptions);

/// <summary>
/// Defines types of text-to-speech operations.
/// </summary>
/// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
/// <seealso cref="PartyLocalChatControl::GetTextToSpeechProfile" />
/// <seealso cref="PartyLocalChatControl::SynthesizeTextToSpeech" />
enum class PartySynthesizeTextToSpeechType
{
    /// <summary>
    /// The audio should be rendered to the local chat control's audio output.
    /// </summary>
    /// <remarks>
    /// This type is typically used for the "narration" scenario where text-to-speech audio is rendered to the local
    /// chat control for arbitrary game-defined scenarios, such as the narration of received text. It may also be used
    /// for the "voice auditioning" scenario where a user compares audio between text-to-speech profiles to select the
    /// profile they prefer to use in text-to-speech voice chat scenarios. The chat control does not need to be in a
    /// network for this functionality.
    /// <para>
    /// The audio will never be transcribed, even if transcription is enabled.
    /// </para>
    /// </remarks>
    Narration,

    /// <summary>
    /// The audio should be rendered to the chat controls to which the local chat control is configured to send audio.
    /// </summary>
    /// <remarks>
    /// This type is typically used for the "text-to-speech voice chat" scenario where a user elects not to
    /// participate in voice chat with their microphone, but still wishes to participate in the voice chat via
    /// text-to-speech audio. The audio will be rendered to the chat controls to which the local chat control has been
    /// configured to send audio via PartyLocalChatControl::SetPermissions(). The chat control does not need to be in
    /// a network for a text-to-speech operation of this type to succeed, but it will have no apparent effect because
    /// there will be no other chat controls to which the local chat control could be configured to send audio.
    /// <para>
    /// Because the audio represents the user's voice, it will be transcribed according to the options specified via
    /// PartyLocalChatControl::SetTranscriptionOptions().
    /// </para>
    /// </remarks>
    VoiceChat,
};

/// <summary>
/// A descriptor containing the data required for a device to connect to a network.
/// </summary>
struct PartyNetworkDescriptor
{
    /// <summary>
    /// A unique identifier for the network.
    /// </summary>
    /// <remarks>
    /// This identifier can be used to correlate locally observed PartyNetwork behavior with remote telemetry gathered
    /// by the Party service and transparent cloud relay. It is recommended that this identifier be recorded alongside
    /// any other information the title records to diagnose network behavior.
    /// </remarks>
    char networkIdentifier[c_networkIdentifierStringLength + 1];

    /// <summary>
    /// The Azure region in which the network was created.
    /// </summary>
    char regionName[c_maxRegionNameStringLength + 1];

    /// <summary>
    /// Connection information for the network used internally by the Party library.
    /// </summary>
    uint8_t opaqueConnectionInformation[c_opaqueConnectionInformationByteCount];
};

/// <summary>
/// Network configuration data.
/// </summary>
struct PartyNetworkConfiguration
{
    /// <summary>
    /// The maximum number of unique users allowed in the network.
    /// </summary>
    /// <remarks>
    /// This value must be greater than 0.
    /// <para>
    /// If a client would violate this limit by calling PartyNetwork::AuthenticateLocalUser(), the operation will fail
    /// asynchronously and PartyAuthenticateLocalUserCompletedStateChange::result will be set to
    /// PartyStateChangeResult::NetworkLimitReached.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyAuthenticateLocalUserCompletedStateChange" />
    /// <seealso cref="PartyStateChangeResult" />
    uint32_t maxUserCount;

    /// <summary>
    /// The maximum number of devices allowed to connect to the network.
    /// </summary>
    /// <remarks>
    /// This value must be between 1 and c_maxNetworkConfigurationMaxDeviceCount inclusive.
    /// <para>
    /// If a client would violate this limit by calling PartyManager::ConnectToNetwork(), the operation will fail
    /// asynchronously and PartyConnectToNetworkCompletedStateChange::result will be set to
    /// PartyStateChangeResult::NetworkLimitReached.
    /// </para>
    /// </remarks>
    /// <seealso cref="c_maxNetworkConfigurationMaxDeviceCount" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    /// <seealso cref="PartyConnectToNetworkCompletedStateChange" />
    /// <seealso cref="PartyStateChangeResult" />
    _Field_range_(1, c_maxNetworkConfigurationMaxDeviceCount) uint32_t maxDeviceCount;

    /// <summary>
    /// The maximum number of users allowed per device.
    /// </summary>
    /// <remarks>
    /// This value must be between 1 and c_maxLocalUsersPerDeviceCount inclusive.
    /// <para>
    /// If a client would violate this limit by calling PartyNetwork::AuthenticateLocalUser(), the operation will fail
    /// asynchronously and PartyAuthenticateLocalUserCompletedStateChange::result will be set to
    /// PartyStateChangeResult::NetworkLimitReached.
    /// </para>
    /// </remarks>
    /// <seealso cref="c_maxLocalUsersPerDeviceCount" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyAuthenticateLocalUserCompletedStateChange" />
    /// <seealso cref="PartyStateChangeResult" />
    _Field_range_(1, c_maxLocalUsersPerDeviceCount) uint32_t maxUsersPerDeviceCount;

    /// <summary>
    /// The maximum number of devices allowed per user.
    /// </summary>
    /// <remarks>
    /// This value must be greater than 0.
    /// <para>
    /// If a client would violate this limit by calling PartyNetwork::AuthenticateLocalUser(), the operation will fail
    /// asynchronously and PartyAuthenticateLocalUserCompletedStateChange::result will be set to
    /// PartyStateChangeResult::NetworkLimitReached.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyAuthenticateLocalUserCompletedStateChange" />
    /// <seealso cref="PartyStateChangeResult" />
    uint32_t maxDevicesPerUserCount;

    /// <summary>
    /// The maximum number of endpoints allowed per device.
    /// </summary>
    /// <remarks>
    /// This value must be between 0 and c_maxNetworkConfigurationMaxEndpointsPerDeviceCount inclusive.
    /// <para>
    /// If a client would violate this limit by calling PartyNetwork::CreateEndpoint() after the network configuration
    /// was made available, the call to PartyNetwork::CreateEndpoint() will fail synchronously. If the client had
    /// already queued a violating number of endpoint creations when the network configuration became available, the
    /// client will be kicked from the network and a PartyNetworkDestroyedStateChange will be generated.
    /// </para>
    /// </remarks>
    /// <seealso cref="c_maxNetworkConfigurationMaxEndpointsPerDeviceCount" />
    /// <seealso cref="PartyNetwork::CreateEndpoint" />
    /// <seealso cref="PartyNetworkDestroyedStateChange" />
    /// <seealso cref="PartyStateChangeResult" />
    _Field_range_(0, c_maxNetworkConfigurationMaxEndpointsPerDeviceCount) uint32_t maxEndpointsPerDeviceCount;
};

/// <summary>
/// Represents a Party library region.
/// </summary>
struct PartyRegion
{
    /// <summary>
    /// The name of the Azure region, such as "eastus2".
    /// </summary>
    char regionName[c_maxRegionNameStringLength + 1];

    /// <summary>
    /// The round trip latency between the local device and the region's datacenter.
    /// </summary>
    uint32_t roundTripLatencyInMilliseconds;
};

/// <summary>
/// Invitation configuration data.
/// </summary>
/// <seealso cref="PartyInvitation" />
/// <seealso cref="PartyInvitationRevocability" />
struct PartyInvitationConfiguration
{
    /// <summary>
    /// The identifier of the invitation.
    /// </summary>
    /// <remarks>
    /// This value may only be null when used as input to PartyManager::CreateNewNetwork() or
    /// PartyNetwork::CreateInvitation().
    /// <para>
    /// The length of this string must be less than or equal to c_maxInvitationIdentifierStringLength.
    /// </para>
    /// </remarks>
    /// <seealso cref="c_maxInvitationIdentifierStringLength" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyInvitation::GetInvitationConfiguration" />
    _Maybenull_ PartyString identifier;

    /// <summary>
    /// The revocability of the invitation.
    /// </summary>
    PartyInvitationRevocability revocability;

    /// <summary>
    /// The number of PlayFab Entity IDs that the invitation allows to authenticate into the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// If this value is 0, all users are allowed to authenticate using the invitation's identifier.
    /// </para>
    /// <para>
    /// This value must be less than or equal to c_maxInvitationEntityIdCount.
    /// </para>
    /// </remarks>
    /// <seealso cref="c_maxInvitationEntityIdCount" />
    _Field_range_(0, c_maxInvitationEntityIdCount) uint32_t entityIdCount;

    /// <summary>
    /// The list of PlayFab Entity IDs that the invitation allows to authenticate into the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// If this list is empty, all users are allowed to authenticate using the invitation's identifier.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyInvitation::GetInvitationConfiguration" />
    _Field_size_(entityIdCount) const PartyString * entityIds;
};

/// <summary>
/// Optional configuration parameters for modifying local queuing behavior when sending a message.
/// </summary>
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
/// <seealso cref="PartyLocalEndpoint::CancelMessages" />
struct PartySendMessageQueuingConfiguration
{
    /// <summary>
    /// The priority of the locally queued message in relation to chat data or messages sent from other local endpoints.
    /// </summary>
    /// <remarks>
    /// <para>
    /// <em>priority</em> must be a value between c_minSendMessageQueuingPriority and c_maxSendMessageQueuingPriority,
    /// inclusive. Higher numbers represent higher relative priority (will be transmitted first) over lower numbers. The
    /// default when no PartySendMessageQueuingConfiguration structure is provided to PartyLocalEndpoint::SendMessage()
    /// is c_defaultSendMessageQueuingPriority, which lies exactly in the middle of the signed integer range (zero).
    /// </para>
    /// <para>
    /// Send queue priority does not modify the order in which messages sent from a given local endpoint are transmitted
    /// or delivered. It only affects the ordering of messages from different local endpoints, or between an endpoint
    /// and internally transmitted chat data, which uses priority c_chatSendMessageQueuingPriority. The local endpoint
    /// send queue that has the messages with the highest priority value will have its messages eligible for
    /// transmission first. If all remaining messages queued by local endpoints are of equal priority, then the
    /// individual messages will be eligible for transmission in the same order in which their
    /// PartyLocalEndpoint::SendMessage() calls occurred.
    /// </para>
    /// <para>
    /// One way to think of the behavior is that high priority messages automatically elevate the priority of all
    /// previous messages from the same local endpoint to the same value to ensure timely delivery of the high priority
    /// message but without breaking the sequential delivery expectations of the messages previously transmitted by the
    /// local endpoint. Other local endpoints have their own send sequence, and thus have no such ordering guarantees
    /// (though the Party library makes a best-effort attempt to preserve the ordering in which they were originally
    /// sent where possible).
    /// </para>
    /// <para>
    /// A message's send queue priority matters when there are more bytes to be sent than the connection can support due
    /// to connection quality or receiver responsiveness. Sending more important messages as higher priority ensures
    /// that they get the first opportunity to use the limited network resources. If you continue to send messages
    /// faster than can successfully be transmitted, lower priority messages may get "starved" and the associated local
    /// endpoint send queue will continue to grow. Be sure to manage such potential growth by canceling extraneous
    /// messages with PartyLocalEndpoint::CancelMessages(), using the <em>timeoutInMilliseconds</em> field to
    /// automatically time out messages that have been queued for too long, or simply reducing the size and/or frequency
    /// of the PartyLocalEndpoint::SendMessage() calls.
    /// </para>
    /// </remarks>
    _Field_range_(c_minSendMessageQueuingPriority, c_maxSendMessageQueuingPriority) int8_t priority;

    /// <summary>
    /// A caller-defined value to use when evaluating the message for applicability with cancel filter expressions.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This message identity value can have any caller-specific meaning and is not interpreted by the Party library
    /// other than for use by PartyLocalEndpoint::CancelMessages() when evaluating whether the message matches the
    /// optionally provided cancel filter expression.
    /// </para>
    /// <para>
    /// A default value of zero is used when no PartySendMessageQueuingConfiguration structure is provided to
    /// PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// Canceling messages can help prevent the local send queue from growing excessively when experiencing poor network
    /// conditions. Canceling message identities that match certain filter expressions works well when you have
    /// categories of messages that are regularly sent with the latest information and should replace any previously
    /// queued out-of-date message that might still be awaiting a transmission opportunity. Canceling can also be useful
    /// when you have an instance or category of opportunistic messages whose loss would not be fatal and that aren't
    /// worth the bandwidth to try transmitting instead of more valuable queued messages.
    /// </para>
    /// <para>
    /// This local identity value is not part of the transmitted data payload. It has no applicability once the message
    /// begins transmitting and can no longer be removed from the local send queue by
    /// PartyLocalEndpoint::CancelMessages().
    /// </para>
    /// </remarks>
    uint32_t identityForCancelFilters;

    /// <summary>
    /// The maximum time, in milliseconds, that the message is permitted to remain in the local send queue awaiting a
    /// transmission opportunity.
    /// </summary>
    /// <remarks>
    /// <para>
    /// If the message has not started transmitting when this timeout elapses due to connection quality or receiver
    /// responsiveness, the message will be aborted and removed from the queue without being sent.
    /// </para>
    /// <para>
    /// A <em>timeoutInMilliseconds</em> value of zero indicates that there should be no timeout and that the message
    /// should remain queued until it is either successfully transmitted, is explicitly canceled, or encounters some
    /// transmission failure such as remote disconnection. Zero is the default when no
    /// PartySendMessageQueuingConfiguration structure is provided to PartyLocalEndpoint::SendMessage().
    /// </para>
    /// <para>
    /// Message send queue timeouts can help prevent the local send queue from growing excessively when experiencing
    /// poor network conditions. They work well with messages that contain time-sensitive, periodic data where it would
    /// be a waste of bandwidth to transmit ones that are stale because a newer complete replacement message is sent
    /// regularly, and the loss of any individual one is not fatal.
    /// </para>
    /// <para>
    /// This timeout value only affects local send queuing. It does not affect the time it takes to actually transmit a
    /// message nor alter how long to wait for the receiver to acknowledge the transmission if necessary.
    /// </para>
    /// </remarks>
    uint32_t timeoutInMilliseconds;
};

/// <summary>
/// A data buffer.
/// </summary>
struct PartyDataBuffer
{
    /// <summary>
    /// The data buffer.
    /// </summary>
    _Field_size_bytes_(bufferByteCount) const void * buffer;

    /// <summary>
    /// The size of the buffer in bytes.
    /// </summary>
    uint32_t bufferByteCount;
};

/// <summary>
/// A translation.
/// </summary>
struct PartyTranslation
{
    /// <summary>
    /// Indicates whether the translation operation succeeded.
    /// </summary>
    /// <remarks>
    /// On success, <em>translation</em> will be a string of non-zero length containing the translated text. On
    /// failure, the string will be empty.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The language code of the translation.
    /// </summary>
    /// <remarks>
    /// The language code will be in BCP 47 format, such as en-US for English (United States). Supported language
    /// codes are enumerated at
    /// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support.
    /// </remarks>
    PartyString languageCode;

    /// <summary>
    /// Additional options describing the translation.
    /// </summary>
    PartyTranslationReceivedOptions options;

    /// <summary>
    /// The translation string.
    /// </summary>
    /// <remarks>
    /// The translation string may be up to <see cref="c_maxChatTextMessageLength" /> characters long, not including
    /// the null terminator. Truncation occurs if the translated string length would exceed that limit, which can
    /// happen due to language differences even though the original string length is less than or equal to <see
    /// cref="c_maxChatTextMessageLength" />. In such a case, <em>options</em> will contain
    /// PartyTranslationReceivedOptions::Truncated. Truncation may occur at an arbitrary point in the UTF-8 byte
    /// sequence and may not result in a complete, valid character or word. Strings are always null terminated, even
    /// when truncated.
    /// </remarks>
    PartyString translation;
};

/// <summary>
/// A generic, base structure representation of an event or change in state.
/// </summary>
/// <remarks>
/// PartyStateChange structures are reported by PartyManager::StartProcessingStateChanges() for the title to handle and
/// then promptly pass back via the PartyManager::FinishProcessingStateChanges() method.
/// <para>
/// The StateChangeType field indicates which kind of state change occurred, and this base structure should then be cast
/// to a more specific derived structure to retrieve additional event-specific information.
/// </para>
/// </remarks>
/// <seealso cref="PartyManager::StartProcessingStateChanges" />
/// <seealso cref="PartyManager::FinishProcessingStateChanges" />
struct PartyStateChange
{
    /// <summary>
    /// The specific type of the state change represented.
    /// </summary>
    /// <remarks>
    /// Use this field to determine which corresponding derived structure is represented by this PartyStateChange
    /// structure header.
    /// </remarks>
    PartyStateChangeType stateChangeType;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RegionsChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::RegionsChanged" />
/// <seealso cref="PartyManager::GetRegions" />
struct PartyRegionsChangedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates whether a background operation to query the list of supported regions and the latency to each region
    /// Succeeded, or provides the reason that it failed.
    /// </summary>
    /// <remarks>
    /// On success, the region list provided by PartyManager::GetRegions() will be populated with the results of the
    /// operation. On failure, the region list provided by PartyManager::GetRegions() will be empty.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::CreateNewNetworkCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::CreateNewNetworkCompleted" />
/// <seealso cref="PartyManager::CreateNewNetwork" />
struct PartyCreateNewNetworkCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the create new network operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The network configuration provided to the call associated with this state change.
    /// </summary>
    PartyNetworkConfiguration networkConfiguration;

    /// <summary>
    /// The number of regions provided to the call associated with this state change.
    /// </summary>
    uint32_t regionCount;

    /// <summary>
    /// The regions provided to the call associated with this state change.
    /// </summary>
    const PartyRegion * regions;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;

    /// <summary>
    /// The network descriptor of the network that was created.
    /// </summary>
    /// <remarks>
    /// This regionName and opaqueConnectionInformation fields are only populated if the result field is
    /// PartyStateChangeResult::Succeeded. The networkIdentifier field should always be populated. If the result field
    /// is PartyStateChangeResult::Succeeded, this network descriptor is serializable via
    /// PartyManager::SerializeNetworkDescriptor().
    /// </remarks>
    PartyNetworkDescriptor networkDescriptor;

    /// <summary>
    /// The identifier for the network's initial invitation.
    /// </summary>
    PartyString appliedInitialInvitationIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ConnectToNetworkCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ConnectToNetworkCompleted" />
/// <seealso cref="PartyManager::ConnectToNetwork" />
struct PartyConnectToNetworkCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the connect to network operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network descriptor provided to the call associated with this state change.
    /// </summary>
    PartyNetworkDescriptor networkDescriptor;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;

    /// <summary>
    /// The network that was connected to.
    /// </summary>
    PartyNetwork * network;
};

/// <summary>
/// Information specific to the PartyStateChangeType::AuthenticateLocalUserCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::AuthenticateLocalUser" />
/// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
struct PartyAuthenticateLocalUserCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the authenticate local user operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The identifier of the invitation used to authenticate into the network.
    /// </summary>
    PartyString invitationIdentifier;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::NetworkConfigurationMadeAvailable type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::NetworkConfigurationMadeAvailable" />
/// <seealso cref="PartyNetwork::GetNetworkConfiguration" />
struct PartyNetworkConfigurationMadeAvailableStateChange : PartyStateChange
{
    /// <summary>
    /// The network where the network configuration was made available.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The newly available network configuration.
    /// </summary>
    PartyNetworkConfiguration * networkConfiguration;
};

/// <summary>
/// Information specific to the PartyStateChangeType::NetworkDescriptorChanged type of state change.
/// </summary>
/// <remarks>
/// This state change is generated when the network descriptor of a network changes due to migration from one server to
/// another. Use PartyNetwork::GetNetworkDescriptor() to get the new network descriptor. The old network descriptor is
/// no longer guaranteed to be usable for connecting to the network, so any outstanding external references to the old
/// network descriptor (such as invitations sent over a social network) should be updated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::NetworkDescriptorChanged" />
/// <seealso cref="PartyNetwork::GetNetworkDescriptor" />
struct PartyNetworkDescriptorChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The network where the network descriptor changed.
    /// </summary>
    PartyNetwork * network;
};

/// <summary>
/// Information specific to the PartyStateChangeType::LocalUserRemoved type of state change.
/// </summary>
/// <remarks>
/// All PartyEndpoints depending on this user will have been destroyed prior to this state change being generated. All
/// PartyChatControls depending on this user will have left the network prior to this state change being generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::LocalUserRemoved" />
/// <seealso cref="PartyNetwork::RemoveLocalUser" />
/// <seealso cref="PartyManager::DestroyLocalUser" />
struct PartyLocalUserRemovedStateChange : PartyStateChange
{
    /// <summary>
    /// The network that the local user was removed from.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The reason the user was removed from the network.
    /// </summary>
    PartyLocalUserRemovedReason removedReason;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RemoveLocalUserCompleted type of state change.
/// </summary>
/// <remarks>
/// All PartyEndpoints and PartyChatControls depending upon this user will have been destroyed with reason
/// PartyDestroyedReason::UserRemoved before this state change is generated. If the user referenced by this state change
/// was the last authenticated user in the network, then all remaining PartyEndpoints on this device, which at this
/// point inherently consists of only endpoints associated with the last user or no user, will also have been destroyed
/// before this state change is generated. An associated PartyLocalUserRemovedStateChange will have been generated
/// before this state change is generated.
/// </remarks>
/// <seealso cref="PartyChatControlDestroyedStateChange" />
/// <seealso cref="PartyChatControlLeftNetworkStateChange" />
/// <seealso cref="PartyEndpointDestroyedStateChange" />
/// <seealso cref="PartyStateChangeType::RemoveLocalUserCompleted" />
/// <seealso cref="PartyNetwork::RemoveLocalUser" />
struct PartyRemoveLocalUserCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the remove local user operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DestroyLocalUserCompleted type of state change.
/// </summary>
/// <remarks>
/// This PartyLocalUser will be removed from all dependent networks prior to this state change. All dependent
/// PartyEndpoint and PartyChatControl objects will be destroyed with reason PartyDestroyedReason::UserRemoved prior to
/// the PartyLocalUser being removed from its dependent networks. Once this state change is returned to
/// PartyManager::FinishProcessingStateChanges(), the PartyLocalUser object memory will become invalid.
/// </remarks>
/// <seealso cref="PartyStateChangeType::DestroyLocalUserCompleted" />
/// <seealso cref="PartyStateChangeType::LocalUserRemoved" />
/// <seealso cref="PartyManager::DestroyLocalUser" />
struct PartyDestroyLocalUserCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the destroy local user operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::LocalUserKicked type of state change.
/// </summary>
/// <remarks>
/// All PartyEndpoints and PartyChatControls depending upon this user will have been destroyed with reason
/// PartyDestroyedReason::Kicked before this state change is generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::LocalUserKicked" />
/// <seealso cref="PartyNetwork::KickUser" />
struct PartyLocalUserKickedStateChange : PartyStateChange
{
    /// <summary>
    /// The network from which the local user was kicked.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user that was kicked.
    /// </summary>
    PartyLocalUser * localUser;
};

/// <summary>
/// Information specific to the PartyStateChangeType::CreateEndpointCompleted type of state change.
/// </summary>
/// <remarks>
/// An associated PartyEndpointCreatedStateChange will be generated before this state change is generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::CreateEndpointCompleted" />
/// <seealso cref="PartyStateChangeType::EndpointCreated" />
/// <seealso cref="PartyNetwork::CreateEndpoint" />
struct PartyCreateEndpointCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the create endpoint Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user provided to the call associated with this state change if one was provided.
    /// </summary>
    _Maybenull_ PartyLocalUser * localUser;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;

    /// <summary>
    /// The endpoint that was created.
    /// </summary>
    PartyLocalEndpoint * localEndpoint;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DestroyEndpointCompleted type of state change.
/// </summary>
/// <remarks>
/// An associated PartyEndpointDestroyedStateChange will be generated before this state change is generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::DestroyEndpointCompleted" />
/// <seealso cref="PartyStateChangeType::EndpointDestroyed" />
/// <seealso cref="PartyNetwork::DestroyEndpoint" />
struct PartyDestroyEndpointCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the destroy endpoint operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The endpoint provided to the call associated with this state change.
    /// </summary>
    PartyLocalEndpoint * localEndpoint;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::EndpointCreated type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::EndpointCreated" />
struct PartyEndpointCreatedStateChange : PartyStateChange
{
    /// <summary>
    /// The network of the endpoint that was created.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The endpoint that was created.
    /// </summary>
    PartyEndpoint * endpoint;
};

/// <summary>
/// Information specific to the PartyStateChangeType::EndpointDestroyed type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::EndpointDestroyed" />
struct PartyEndpointDestroyedStateChange : PartyStateChange
{
    /// <summary>
    /// The network of the endpoint that was destroyed.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The endpoint that was destroyed.
    /// </summary>
    PartyEndpoint * endpoint;

    /// <summary>
    /// The reason the endpoint was destroyed.
    /// </summary>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RemoteDeviceCreated type of state change.
/// </summary>
/// <remarks>
/// This state change indicates that the device was just created.
/// </remarks>
/// <seealso cref="PartyStateChangeType::RemoteDeviceCreated" />
struct PartyRemoteDeviceCreatedStateChange : PartyStateChange
{
    /// <summary>
    /// The device that was created.
    /// </summary>
    PartyDevice * device;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RemoteDeviceDestroyed type of state change.
/// </summary>
/// <remarks>
/// This state change is generated when device has left all networks.
/// </remarks>
/// <seealso cref="PartyStateChangeType::RemoteDeviceDestroyed" />
struct PartyRemoteDeviceDestroyedStateChange : PartyStateChange
{
    /// <summary>
    /// The device that was destroyed.
    /// </summary>
    PartyDevice * device;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RemoteDeviceJoinedNetwork type of state change.
/// </summary>
/// <remarks>
/// This state change indicates that the device has just joined the network.
/// </remarks>
/// <seealso cref="PartyStateChangeType::RemoteDeviceJoinedNetwork" />
struct PartyRemoteDeviceJoinedNetworkStateChange : PartyStateChange
{
    /// <summary>
    /// The device that joined.
    /// </summary>
    PartyDevice * device;

    /// <summary>
    /// The network that was joined.
    /// </summary>
    PartyNetwork * network;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RemoteDeviceLeftNetwork type of state change.
/// </summary>
/// <remarks>
/// This state change indicates that the device just left the network.
/// </remarks>
/// <seealso cref="PartyStateChangeType::RemoteDeviceLeftNetwork" />
struct PartyRemoteDeviceLeftNetworkStateChange : PartyStateChange
{
    /// <summary>
    /// The reason the device left the network.
    /// </summary>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The device that left.
    /// </summary>
    PartyDevice * device;

    /// <summary>
    /// The network that was left.
    /// </summary>
    PartyNetwork * network;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DevicePropertiesChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::DevicePropertiesChanged" />
/// <seealso cref="PartyLocalDevice::SetSharedProperties" />
/// <seealso cref="PartyDevice::GetSharedProperty" />
struct PartyDevicePropertiesChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The device where the properties changed.
    /// </summary>
    PartyDevice * device;

    /// <summary>
    /// The number of changed properties.
    /// </summary>
    uint32_t propertyCount;

    /// <summary>
    /// The keys of the properties that have changed.
    /// </summary>
    /// <remarks>
    /// Each key can represent an add, update, or delete. If the key was deleted, PartyDevice::GetSharedProperty() will
    /// return nullptr for the value.
    /// </remarks>
    _Field_size_(propertyCount) const PartyString * keys;
};

/// <summary>
/// Information specific to the PartyStateChangeType::LeaveNetworkCompleted type of state change.
/// </summary>
/// <remarks>
/// An associated PartyNetworkDestroyedStateChange will be generated before this state change is generated. The network
/// object <em>network</em> is only valid until this state change is returned to
/// PartyManager::FinishProcessingStateChanges().
/// </remarks>
/// <seealso cref="PartyStateChangeType::LeaveNetworkCompleted" />
/// <seealso cref="PartyNetwork::LeaveNetwork" />
struct PartyLeaveNetworkCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the leave network operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::NetworkDestroyed type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::NetworkDestroyed" />
struct PartyNetworkDestroyedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates why the network was destroyed.
    /// </summary>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network that was destroyed.
    /// </summary>
    PartyNetwork * network;
};

/// <summary>
/// Information specific to the PartyStateChangeType::EndpointMessageReceived type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::EndpointMessageReceived" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
struct PartyEndpointMessageReceivedStateChange : PartyStateChange
{
    /// <summary>
    /// The network containing the endpoint on which the message was received.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The endpoint which sent the message.
    /// </summary>
    PartyEndpoint * senderEndpoint;

    /// <summary>
    /// The number of local endpoints to which the message was sent. This value will always be
    /// greater than zero. If the sender specified an empty target endpoints array in the
    /// PartyLocalEndpoint::SendMessage() call that resulted in this state change, <c>receiverEndpointCount</c> and
    /// <c>receiverEndpoints</c> will contain all local endpoints.
    /// </summary>
    uint32_t receiverEndpointCount;

    /// <summary>
    /// The local endpoints to which the message was sent. This array will never be empty. If the sender specified an
    /// empty target endpoints array in the PartyLocalEndpoint::SendMessage() call that resulted in this state change,
    /// <c>receiverEndpointCount</c> and <c>receiverEndpoints</c> will contain all local endpoints.
    /// </summary>
    _Field_size_(receiverEndpointCount) PartyLocalEndpointArray receiverEndpoints;

    /// <summary>
    /// The options used to send the message.
    /// </summary>
    PartyMessageReceivedOptions options;

    /// <summary>
    /// The size of the message in bytes.
    /// </summary>
    uint32_t messageSize;

    /// <summary>
    /// The message buffer.
    /// </summary>
    _Field_size_bytes_(messageSize) const void * messageBuffer;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DataBuffersReturned type of state change.
/// </summary>
/// <remarks>
/// This state change is only returned if the corresponding call to PartyLocalEndpoint::SendMessage() included the
/// PartySendMessageOptions::DontCopyDataBuffers option. This state change is returned once the data buffers passed with
/// this call are no longer in use by the PartyManager instance.
/// </remarks>
/// <seealso cref="PartyStateChangeType::DataBuffersReturned" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
struct PartyDataBuffersReturnedStateChange : PartyStateChange
{
    /// <summary>
    /// The network on which the message was sent.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local endpoint used to send the message.
    /// </summary>
    PartyLocalEndpoint * localSenderEndpoint;

    /// <summary>
    /// The number of data buffers.
    /// </summary>
    uint32_t dataBufferCount;

    /// <summary>
    /// The data buffers.
    /// </summary>
    _Field_size_(dataBufferCount) const PartyDataBuffer * dataBuffers;

    /// <summary>
    /// The message identifier provided to the call associated with this state change.
    /// </summary>
    void * messageIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::EndpointPropertiesChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::EndpointPropertiesChanged" />
/// <seealso cref="PartyLocalEndpoint::SetSharedProperties" />
/// <seealso cref="PartyEndpoint::GetSharedProperty" />
struct PartyEndpointPropertiesChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The endpoint where the properties changed.
    /// </summary>
    PartyEndpoint * endpoint;

    /// <summary>
    /// The number of changed properties.
    /// </summary>
    uint32_t propertyCount;

    /// <summary>
    /// The keys of the properties that have changed.
    /// </summary>
    /// <remarks>
    /// Each key can represent an add, update, or delete. If the key was deleted, PartyEndpoint::GetSharedProperty()
    /// will return nullptr for the value.
    /// </remarks>
    _Field_size_(propertyCount) const PartyString * keys;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SynchronizeMessagesBetweenEndpointsCompleted type of state change.
/// </summary>
/// <remarks>
/// This state change signifies that the synchronize operation has completed. This means that all data sends sent to or
/// from endpoints specified in the call to PartyManager::SynchronizeMessagesBetweenEndpoints before the call to
/// PartyManager::SynchronizeMessagesBetweenEndpoints have completed. Data sends queued after the call to
/// PartyManager::SynchronizeMessagesBetweenEndpoints will now start being sent and received.
/// </remarks>
/// <seealso cref="PartyStateChangeType::SynchronizeMessagesBetweenEndpointsCompleted" />
/// <seealso cref="PartyLocalEndpoint::SendMessage" />
/// <seealso cref="PartyManager::SynchronizeMessagesBetweenEndpoints" />
struct PartySynchronizeMessagesBetweenEndpointsCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// The number of endpoints that were synchronized.
    /// </summary>
    uint32_t endpointCount;

    /// <summary>
    /// The endpoints that were synchronized.
    /// </summary>
    /// <remarks>
    /// The list of endpoints will not include any endpoints that were specified but were destroyed before the
    /// synchronize operation completed.
    /// </remarks>
    _Field_size_(endpointCount) PartyEndpointArray endpoints;

    /// <summary>
    /// The options provided to the call associated with this state change.
    /// </summary>
    PartySynchronizeMessagesBetweenEndpointsOptions options;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::CreateInvitationCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::CreateInvitationCompleted" />
/// <seealso cref="PartyStateChangeType::InvitationCreated" />
/// <seealso cref="PartyNetwork::CreateInvitation" />
struct PartyCreateInvitationCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the PartyNetwork::CreateInvitation() operation succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user that created the invitation.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;

    /// <summary>
    /// The invitation created for the network.
    /// </summary>
    PartyInvitation * invitation;
};

/// <summary>
/// Information specific to the PartyStateChangeType::RevokeInvitationCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::RevokeInvitationCompleted" />
/// <seealso cref="PartyStateChangeType::InvitationDestroyed" />
/// <seealso cref="PartyNetwork::RevokeInvitation" />
struct PartyRevokeInvitationCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the PartyNetwork::RevokeInvitation() operation succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The local user used to revoke the invitation.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The revoked invitation.
    /// <summary>
    PartyInvitation * invitation;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::InvitationCreated type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::InvitationCreated" />
struct PartyInvitationCreatedStateChange : PartyStateChange
{
    /// <summary>
    /// The network of the invitation that was created.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The invitation that was created.
    /// </summary>
    /// <remarks>
    /// Upon receiving this state change, the invitation object will be queryable via PartyNetwork::GetInvitations().
    /// </remarks>
    PartyInvitation * invitation;
};

/// <summary>
/// Information specific to the PartyStateChangeType::InvitationDestroyed type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::InvitationDestroyed" />
struct PartyInvitationDestroyedStateChange : PartyStateChange
{
    /// <summary>
    /// The network of the invitation that was destroyed.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The invitation that was destroyed.
    /// </summary>
    /// <remarks>
    /// Upon receiving this state change, the invitation object will no longer be queryable via
    /// PartyNetwork::GetInvitations().
    /// </remarks>
    PartyInvitation * invitation;

    /// <summary>
    /// The reason the invitation was destroyed.
    /// </summary>
    /// <remarks>
    /// If the invitation object was destroyed because it was explicitly revoked via PartyNetwork::RevokeInvitation()
    /// or automatically revoked when the creating local user left the network, this value will be
    /// PartyDestroyedReason::Requested. If the invitation object was destroyed because the local client is no longer
    /// authenticated in the network, this value will be PartyDestroyedReason::DeviceLostAuthentication.
    /// </remarks>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::NetworkPropertiesChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::NetworkPropertiesChanged" />
/// <seealso cref="PartyNetwork::GetSharedProperty" />
/// <seealso cref="PartyNetwork::SetSharedProperties" />
struct PartyNetworkPropertiesChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The network where the properties changed.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The number of changed properties.
    /// </summary>
    uint32_t propertyCount;

    /// <summary>
    /// The keys of the properties that have changed.
    /// </summary>
    /// <remarks>
    /// Each key can represent an add, update, or delete. If the key was deleted, PartyNetwork::GetSharedProperty() will
    /// return nullptr for the value.
    /// </remarks>
    _Field_size_(propertyCount) const PartyString * keys;
};

/// <summary>
/// Information specific to the PartyStateChangeType::KickDeviceCompleted type of state change.
/// </summary>
/// <remarks>
/// All associated PartyRemoteDeviceDestroyedStateChange and PartyEndpointDestroyedStateChange state changes will be
/// generated before this state change is generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::KickDeviceCompleted" />
/// <seealso cref="PartyNetwork::KickDevice" />
struct PartyKickDeviceCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the kick device operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The device provided to the call associated with this state change.
    /// </summary>
    PartyDevice * kickedDevice;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::KickUserCompleted type of state change.
/// </summary>
/// <remarks>
/// All associated PartyRemoteDeviceDestroyedStateChange, PartyEndpointDestroyedStateChange, and
/// PartyLocalUserKickedStateChange state changes will be generated before this state change is generated.
/// </remarks>
/// <seealso cref="PartyStateChangeType::KickUserCompleted" />
/// <seealso cref="PartyNetwork::KickUser" />
struct PartyKickUserCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the kick user operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The Entity ID provided to the call associated with this state change.
    /// </summary>
    PartyString kickedEntityId;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::CreateChatControlCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::CreateChatControlCompleted" />
/// <seealso cref="PartyLocalDevice::CreateChatControl" />
struct PartyCreateChatControlCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the chat control creation operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The local device used in the call associated with this state change.
    /// </summary>
    PartyLocalDevice * localDevice;

    /// <summary>
    /// The local user provided to the call associated with this state change.
    /// </summary>
    PartyLocalUser * localUser;

    /// <summary>
    /// The language code provided to the call associated with this state change.
    /// </summary>
    PartyString languageCode;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;

    /// <summary>
    /// The chat control that was created.
    /// </summary>
    PartyLocalChatControl * localChatControl;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DestroyChatControlCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::DestroyChatControlCompleted" />
/// <seealso cref="PartyLocalDevice::DestroyChatControl" />
struct PartyDestroyChatControlCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the chat control destruction operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The local device used in the call associated with this state change.
    /// </summary>
    PartyLocalDevice * localDevice;

    /// <summary>
    /// The chat control that was destroyed.
    /// </summary>
    /// <remarks>
    /// The memory remains valid until this state change is returned.
    /// </remarks>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatControlCreated type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatControlCreated" />
/// <seealso cref="PartyLocalDevice::CreateChatControl" />
struct PartyChatControlCreatedStateChange : PartyStateChange
{
    /// <summary>
    /// The chat control that was created.
    /// </summary>
    PartyChatControl * chatControl;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatControlDestroyed type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatControlDestroyed" />
/// <seealso cref="PartyLocalDevice::DestroyChatControl" />
struct PartyChatControlDestroyedStateChange : PartyStateChange
{
    /// <summary>
    /// The chat control that was destroyed.
    /// </summary>
    /// <remarks>
    /// The memory remains valid until this state change is returned.
    /// </remarks>
    PartyChatControl * chatControl;

    /// <summary>
    /// The reason the chat control was destroyed.
    /// </summary>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetChatAudioEncoderBitrateCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SetChatAudioEncoderBitrateCompleted" />
/// <seealso cref="PartyLocalChatControl::SetChatAudioEncoderBitrateCompleted" />
struct PartySetChatAudioEncoderBitrateCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the encoder bitrate configuration operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The local chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The bitrate provided to the call associated with this state change.
    /// </summary>
    uint32_t bitrate;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatTextReceived type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatTextReceived" />
/// <seealso cref="PartyLocalChatControl::SendText" />
struct PartyChatTextReceivedStateChange : PartyStateChange
{
    /// <summary>
    /// The chat control object that originated the text message.
    /// </summary>
    PartyChatControl * senderChatControl;

    /// <summary>
    /// The number of local receiver chat controls to which the text message is addressed.
    /// </summary>
    uint32_t receiverChatControlCount;

    /// <summary>
    /// The local receiver chat controls to which the text message is addressed.
    /// </summary>
    _Field_size_(receiverChatControlCount) PartyLocalChatControlArray receiverChatControls;

    /// <summary>
    /// The received chat text.
    /// </summary>
    /// <remarks>
    /// The string may be up to <see cref="c_maxChatTextMessageLength" /> characters long, not including the null
    /// terminator.
    /// </remarks>
    PartyString chatText;

    /// <summary>
    /// The size of the data associated with this text message.
    /// </summary>
    uint32_t dataSize;

    /// <summary>
    /// The data associated with this text message.
    /// </summary>
    _Field_size_bytes_(dataSize) const void * data;

    /// <summary>
    /// The number of translations associated with the chat text.
    /// </summary>
    /// <remarks>
    /// Translations will be provided if PartyTextChatOptions::TranslateToLocalLanguage had previously been specified
    /// via PartyLocalChatControl::SetTextChatOptions() on a chat control local to this device. There may be more than
    /// one translation if multiple local chat controls have enabled translation and the local chat controls have
    /// specified different languages via either PartyLocalDevice::CreateChatControl() or
    /// PartyLocalChatControl::SetLanguage(). In that case, the app can compare the <em>languageCode</em> field of
    /// each PartyTranslation in <em>translations</em> against the language code, obtained via
    /// PartyLocalChatControl::GetLanguage(), for each local chat control in <em>receiverChatControls</em> to
    /// determine the target local chat control for each translation.
    /// </remarks>
    /// <seealso cref="PartyLocalDevice::CreateChatControl" />
    /// <seealso cref="PartyLocalChatControl::SetTextChatOptions" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    uint32_t translationCount;

    /// <summary>
    /// An array containing the translations of the chat text string.
    /// </summary>
    /// <remarks>
    /// Translations will be provided if PartyTextChatOptions::TranslateToLocalLanguage had previously been specified
    /// via PartyLocalChatControl::SetTextChatOptions() on a chat control local to this device. There may be more than
    /// one translation if multiple local chat controls have enabled translation and the local chat controls have
    /// specified different languages via either PartyLocalDevice::CreateChatControl() or
    /// PartyLocalChatControl::SetLanguage(). In that case, the app can compare the <em>languageCode</em> field of
    /// each PartyTranslation in <em>translations</em> against the language code, obtained via
    /// PartyLocalChatControl::GetLanguage(), for each local chat control in <em>receiverChatControls</em> to
    /// determine the target local chat control for each translation.
    /// </remarks>
    /// A translation corresponding to the language for each chat control in <em>receiverChatControls</em> that has
    /// enabled translation will be provided, even if the source chat control's language is the same as the local
    /// chat control's language. In such a case, the chat text and translation strings will be identical.
    /// </para>
    /// <seealso cref="PartyLocalDevice::CreateChatControl" />
    /// <seealso cref="PartyLocalChatControl::SetTextChatOptions" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    _Field_size_(translationCount) PartyTranslation * translations;
};

/// <summary>
/// Information specific to the PartyStateChangeType::VoiceChatTranscriptionReceived type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::VoiceChatTranscriptionReceived" />
struct PartyVoiceChatTranscriptionReceivedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the transcription operation Succeeded or provides the reason that it failed.
    /// </summary>
    /// <remarks>
    /// On success, the <em>transcription</em> field will be a string of non-zero length. On failure, the string will be
    /// empty. Failure indicates that a transcription operation was attempted for the speaker but could not be
    /// completed. If transcription is enabled at the request of the user associated with the chat control, and the
    /// transcription messages are shown via UI, it is recommended that failures also be indicated to the user in order
    /// to provide feedback as to whether transcriptions are pending or have failed.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control object that originated the transcription message.
    /// </summary>
    PartyChatControl * senderChatControl;

    /// <summary>
    /// The number of local receiver chat controls to which the transcription is addressed.
    /// </summary>
    uint32_t receiverChatControlCount;

    /// <summary>
    /// The local receiver chat controls to which the transcription is addressed.
    /// </summary>
    _Field_size_(receiverChatControlCount) PartyLocalChatControlArray receiverChatControls;

    /// <summary>
    /// The transcribed voice chat text.
    /// </summary>
    /// <remarks>
    /// The string may be up to <see cref="c_maxChatTextMessageLength" /> characters long, not including the null
    /// terminator. The string will always be empty when the <em>result</em> field indicates failures.
    /// </remarks>
    PartyString transcription;

    /// <summary>
    /// Indicates the phrase type of the text provided in the <em>transcription</em> field.
    /// </summary>
    /// <remarks>
    /// The type will always be PartyVoiceChatTranscriptionPhraseType::Final when the <em>result</em> field indicates
    /// failure.
    /// </remarks>
    PartyVoiceChatTranscriptionPhraseType type;

    /// <summary>
    /// The number of translations associated with the transcribed voice chat text.
    /// </summary>
    /// <remarks>
    /// Translations will be provided if PartyVoiceChatTranscriptionOptions::TranslateToLocalLanguage had previously
    /// been specified via PartyLocalChatControl::SetTranscriptionOptions() on a chat control local to this device.
    /// There may be more than one translation if multiple local chat controls have enabled translation and the local
    /// chat controls have specified different languages via either PartyLocalDevice::CreateChatControl() or
    /// PartyLocalChatControl::SetLanguage(). In that case, the app can compare the <em>languageCode</em> field of
    /// each PartyTranslation in <em>translations</em> against the language code, obtained via
    /// PartyLocalChatControl::GetLanguage(), for each local chat control in <em>receiverChatControls</em> to
    /// determine the target local chat control for each translation.
    /// </remarks>
    /// <seealso cref="PartyLocalDevice::CreateChatControl" />
    /// <seealso cref="PartyLocalChatControl::SetTranscriptionOptions" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    uint32_t translationCount;

    /// <summary>
    /// An array containing the translations of the voice chat transcription string.
    /// </summary>
    /// <remarks>
    /// Translations will be provided if PartyVoiceChatTranscriptionOptions::TranslateToLocalLanguage had previously
    /// been specified via PartyLocalChatControl::SetTranscriptionOptions() on a chat control local to this device.
    /// There may be more than one translation if multiple local chat controls have enabled translation and the local
    /// chat controls have specified different languages via either PartyLocalDevice::CreateChatControl() or
    /// PartyLocalChatControl::SetLanguage(). In that case, the app can compare the <em>languageCode</em> field of
    /// each PartyTranslation in <em>translations</em> against the language code, obtained via
    /// PartyLocalChatControl::GetLanguage(), for each local chat control in <em>receiverChatControls</em> to
    /// determine the target local chat control for each translation.
    /// <para>
    /// A translation corresponding to the language for each chat control in <em>receiverChatControls</em> that has
    /// enabled translation will be provided, even if the speaking chat control's language is the same as the local
    /// chat control's language. In such a case, the transcription and translation strings will be identical.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyLocalDevice::CreateChatControl" />
    /// <seealso cref="PartyLocalChatControl::SetTranscriptionOptions" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    _Field_size_(translationCount) PartyTranslation * translations;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetChatAudioInputCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SetChatAudioInputCompleted" />
/// <seealso cref="PartyLocalChatControl::SetAudioInput" />
struct PartySetChatAudioInputCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the audio input configuration operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The audio device selection type provided to the call associated with this state change.
    /// </summary>
    PartyAudioDeviceSelectionType audioDeviceSelectionType;

    /// <summary>
    /// The device context provided to the call associated with this state change.
    /// </summary>
    PartyString audioDeviceSelectionContext;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetChatAudioOutputCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SetChatAudioOutputCompleted" />
/// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
struct PartySetChatAudioOutputCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the audio output configuration operation Succeeded or provides the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The audio device selection type provided to the call associated with this state change.
    /// </summary>
    PartyAudioDeviceSelectionType audioDeviceSelectionType;

    /// <summary>
    /// The device context provided to the call associated with this state change.
    /// </summary>
    PartyString audioDeviceSelectionContext;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::LocalChatAudioInputChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::LocalChatAudioInputChanged" />
/// <seealso cref="PartyLocalChatControl::SetAudioInput" />
struct PartyLocalChatAudioInputChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The local chat control which had an audio input state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// Indicates the new state of the audio input associated with the chat control.
    /// </summary>
    PartyAudioInputState state;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::LocalChatAudioOutputChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::LocalChatAudioOutputChanged" />
/// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
struct PartyLocalChatAudioOutputChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The local chat control which had an audio output state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// Indicates the new state of the audio output associated with the chat control.
    /// </summary>
    PartyAudioOutputState state;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetTextToSpeechProfileCompleted type of state change.
/// </summary>
/// <remarks>
/// At most, one PartySetTextToSpeechProfileCompletedStateChange object will be returned in any state change batch from
/// PartyManager::StartProcessingStateChanges().
/// </remarks>
/// <seealso cref="PartyStateChangeType::SetTextToSpeechProfileCompleted" />
/// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
struct PartySetTextToSpeechProfileCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    /// <remarks>
    /// On success, PartyLocalChatControl::GetTextToSpeechProfile() will return the full profile object corresponding to
    /// the profile identifier provided to the PartyLocalChatControl::SetTextToSpeechProfile() call associated with this
    /// state change. On failure, PartyLocalChatControl::GetTextToSpeechProfile() will return null.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The type of text-to-speech operation provided to the call associated with this state change.
    /// </summary>
    PartySynthesizeTextToSpeechType type;

    /// <summary>
    /// The profile identifier provided to the call associated with this state change.
    /// </summary>
    PartyString profileIdentifier;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SynthesizeTextToSpeechCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SynthesizeTextToSpeechCompleted" />
/// <seealso cref="PartyLocalChatControl::SynthesizeTextToSpeech" />
struct PartySynthesizeTextToSpeechCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The type of text-to-speech operation provided to the call associated with this state change.
    /// </summary>
    PartySynthesizeTextToSpeechType type;

    /// <summary>
    /// The synthesized text provided to the call associated with this state change.
    /// </summary>
    /// <remarks>
    /// If the accompanying result was a success, the audio synthesized for this text has been queued in the audio
    /// stream but may not have been transmitted yet.
    /// </remarks>
    PartyString textToSynthesize;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetLanguageCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SetLanguageCompleted" />
/// <seealso cref="PartyLocalChatControl::SetLanguage" />
struct PartySetLanguageCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The language code provided to the call associated with this state change.
    /// </summary>
    PartyString languageCode;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::SetTranscriptionOptionsCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::SetTranscriptionOptionsCompleted" />
/// <seealso cref="PartyLocalChatControl::SetTranscriptionOptions" />
struct PartySetTranscriptionOptionsCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    /// <remarks>
    /// On success, internal state has updated to reflect whether transcription operations should be attempted on behalf
    /// of <em>localChatControl</em>. Success does not guarantee that transcription operations will complete
    /// successfully. Failures to complete transcription operations will be exposed through the <em>result</em> field of
    /// the PartyStateChangeType::VoiceChatTranscriptionReceived state change.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The transcription options provided to the call associated with this state change.
    /// </summary>
    PartyVoiceChatTranscriptionOptions options;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::PartySetTextChatOptionsCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::PartySetTextChatOptionsCompleted" />
/// <seealso cref="PartyLocalChatControl::SetTranscriptionOptions" />
struct PartySetTextChatOptionsCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control used in the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The text chat options provided to the call associated with this state change.
    /// </summary>
    PartyTextChatOptions options;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatControlPropertiesChanged type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatControlPropertiesChanged" />
/// <seealso cref="PartyLocalChatControl::SetSharedProperties" />
/// <seealso cref="PartyChatControl::GetSharedProperty" />
struct PartyChatControlPropertiesChangedStateChange : PartyStateChange
{
    /// <summary>
    /// The chat control where the properties changed.
    /// </summary>
    PartyChatControl * chatControl;

    /// <summary>
    /// The number of changed properties.
    /// </summary>
    uint32_t propertyCount;

    /// <summary>
    /// The keys of the properties that have changed.
    /// </summary>
    /// <remarks>
    /// Each key can represent an add, update, or delete. If the key was deleted, PartyChatControl::GetSharedProperty()
    /// will return nullptr for the value.
    /// </remarks>
    _Field_size_(propertyCount) const PartyString * keys;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatControlJoinedNetwork type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatControlJoinedNetwork" />
/// <seealso cref="PartyLocalChatControl::ConnectChatControl" />
struct PartyChatControlJoinedNetworkStateChange : PartyStateChange
{
    /// <summary>
    /// The network joined.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The chat control that joined the network.
    /// </summary>
    PartyChatControl * chatControl;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ChatControlLeftNetwork type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ChatControlLeftNetwork" />
/// <seealso cref="PartyLocalChatControl::DisconnectChatControl" />
struct PartyChatControlLeftNetworkStateChange : PartyStateChange
{
    /// <summary>
    /// The reason the chat control left the network.
    /// </summary>
    PartyDestroyedReason reason;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network left.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The chat control that left the network.
    /// </summary>
    PartyChatControl * chatControl;
};

/// <summary>
/// Information specific to the PartyStateChangeType::ConnectChatControlCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::ConnectChatControlCompleted" />
/// <seealso cref="PartyLocalChatControl::ConnectChatControl" />
struct PartyConnectChatControlCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The chat control provided to the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::DisconnectChatControlCompleted type of state change.
/// </summary>
/// <seealso cref="PartyStateChangeType::DisconnectChatControlCompleted" />
/// <seealso cref="PartyLocalChatControl::DisconnectChatControl" />
struct PartyDisconnectChatControlCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The network used in the call associated with this state change.
    /// </summary>
    PartyNetwork * network;

    /// <summary>
    /// The chat control provided to the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

/// <summary>
/// Information specific to the PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted type of state
/// change.
/// </summary>
/// <seealso cref="PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted" />
/// <seealso cref="PartyLocalChatControl::PopulateAvailableTextToSpeechProfiles" />
struct PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange : PartyStateChange
{
    /// <summary>
    /// Indicates that the operation Succeeded or the reason that it failed.
    /// </summary>
    /// <remarks>
    /// On success, the profile list provided by PartyLocalChatControl::GetAvailableTextToSpeechProfiles() will be
    /// populated with the results of the operation. On failure, the profile list will remain unchanged.
    /// </remarks>
    PartyStateChangeResult result;

    /// <summary>
    /// A diagnostic value providing additional troubleshooting information regarding any potential error condition.
    /// </summary>
    /// <remarks>
    /// The human-readable form of this error detail can be retrieved via PartyManager::GetErrorMessage().
    /// </remarks>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError errorDetail;

    /// <summary>
    /// The chat control provided to the call associated with this state change.
    /// </summary>
    PartyLocalChatControl * localChatControl;

    /// <summary>
    /// The async identifier provided to the call associated with this state change.
    /// </summary>
    void * asyncIdentifier;
};

#pragma pack(pop)

/// <summary>
/// A callback invoked every time a new memory buffer must be dynamically allocated by the Party library.
/// </summary>
/// <remarks>
/// This callback is optionally installed using the PartyManager::SetMemoryCallbacks() method.
/// <para>
/// The callback must allocate and return a pointer to a contiguous block of memory of the specified size that will
/// remain valid until the title's corresponding <see cref="PartyFreeMemoryCallback" /> is invoked to release it. If
/// this is not possible, the callback must return nullptr to fail the allocation. Memory allocation failures are
/// sometimes considered benign but will usually cause current Party library operation(s) to fail.
/// </para>
/// <para>
/// Every non-nullptr returned by this method will be subsequently passed to the corresponding <see
/// cref="PartyFreeMemoryCallback" /> once the memory is no longer needed.
/// </para>
/// </remarks>
/// <param name="size">
/// The size of the allocation to be made. This value will never be zero.
/// </param>
/// <param name="memoryTypeId">
/// An opaque identifier representing the Party library internal category of memory being allocated. This value should
/// be ignored.
/// </param>
/// <returns>
/// A pointer to an allocated block of memory of the specified size, or nullptr if the allocation failed.
/// </returns>
/// <seealso cref="PartyFreeMemoryCallback" />
/// <seealso cref="PartyManager::SetMemoryCallbacks" />
/// <seealso cref="PartyManager::GetMemoryCallbacks" />
typedef
_Ret_maybenull_
_Post_writable_byte_size_(size) void *
(PARTY_CALLBACK * PartyAllocateMemoryCallback)(
    size_t size,
    uint32_t memoryTypeId
    );

/// <summary>
/// A callback invoked every time a previously allocated memory buffer is no longer needed by the Party library and can
/// be freed.
/// </summary>
/// <remarks>
/// This callback is optionally installed using the PartyManager::SetMemoryCallbacks() method.
/// <para>
/// The callback is invoked whenever the Party library has finished using a memory buffer previously returned by the
/// title's corresponding <see cref="PartyAllocateMemoryCallback" />, so that the title can free the memory buffer.
/// </para>
/// </remarks>
/// <param name="pointer">
/// A pointer to a memory buffer previously allocated. This value will never be nullptr.
/// </param>
/// <param name="memoryTypeId">
/// An opaque identifier representing the Party library internal category of memory being freed. This value should be
/// ignored.
/// </param>
/// <seealso cref="PartyAllocateMemoryCallback" />
/// <seealso cref="PartyManager::SetMemoryCallbacks" />
/// <seealso cref="PartyManager::GetMemoryCallbacks" />
typedef
void
(PARTY_CALLBACK * PartyFreeMemoryCallback)(
    _Post_invalid_ void * pointer,
    uint32_t memoryTypeId
    );

/// <summary>
/// Represents a local user.
/// </summary>
/// <seealso cref="PartyManager::CreateLocalUser" />
/// <seealso cref="PartyManager::GetLocalUsers" />
/// <seealso cref="PartyManager::DestroyLocalUser" />
/// <seealso cref="PartyManager::CreateNewNetwork" />
/// <seealso cref="PartyManager::CreateChatControl" />
/// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
/// <seealso cref="PartyNetwork::RemoveLocalUser" />
/// <seealso cref="PartyNetwork::CreateInvitation" />
/// <seealso cref="PartyNetwork::RevokeInvitation" />
/// <seealso cref="PartyNetwork::CreateEndpoint" />
class PartyLocalUser
{
public:
    /// <summary>
    /// Gets the Entity ID associated with this local user.
    /// </summary>
    /// <remarks>
    /// The retrieved Entity ID is identical to the Entity ID provided by the title via PartyManager::CreateLocalUser().
    /// <para>
    /// The memory for the Entity ID string remains valid for the life of the local user, which is until its
    /// DestroyLocalUserCompleted state change has been provided via PartyManager::StartProcessingStateChanges() and all
    /// state changes referencing the local user have been returned to PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="entityId">
    /// The output Entity ID.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::CreateLocalUser" />
    PartyError GetEntityId(
        _Outptr_ PartyString * entityId
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this local user
    /// object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyLocalUser::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this local user object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the local user without requiring a mapping lookup. The value is retrieved using the
    /// PartyLocalUser::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the player object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyLocalUser::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyLocalUser() = delete;
    PartyLocalUser(const PartyLocalUser&) = delete;
    PartyLocalUser(PartyLocalUser&&) = delete;
    PartyLocalUser& operator=(const PartyLocalUser&) = delete;
    PartyLocalUser& operator=(PartyLocalUser&&) = delete;
    ~PartyLocalUser() = delete;
};

/// <summary>
/// Represents an endpoint in a network.
/// </summary>
class PartyEndpoint
{
public:
    /// <summary>
    /// Gets the PartyLocalEndpoint version of this endpoint.
    /// </summary>
    /// <remarks>
    /// If this endpoint is not a local endpoint, nullptr is returned.
    /// </remarks>
    PartyError GetLocal(
        _Outptr_result_maybenull_ PartyLocalEndpoint ** localEndpoint
        ) const party_no_throw;

    /// <summary>
    /// Gets the PlayFab Entity ID of the user associated with this endpoint.
    /// </summary>
    /// <remarks>
    /// If this endpoint is not associated with a user, <paramref name="entityId" /> is set to nullptr.
    /// <para>
    /// The memory for the Entity ID string remains valid for the life of the endpoint, which is until its
    /// EndpointDestroyed and/or DestroyEndpointCompleted state change, depending on the type of destruction that
    /// occurred, has been provided via PartyManager::StartProcessingStateChanges() and all state changes referencing
    /// the endpoint have been returned to PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="entityId">
    /// The output Entity ID.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError GetEntityId(
        _Outptr_result_maybenull_ PartyString * entityId
        ) const party_no_throw;

    /// <summary>
    /// Gets the network associated with this endpoint.
    /// </summary>
    PartyError GetNetwork(
        _Outptr_ PartyNetwork ** network
        ) const party_no_throw;

    /// <summary>
    /// Gets the device associated with this endpoint.
    /// </summary>
    PartyError GetDevice(
        _Outptr_ PartyDevice ** device
        ) const party_no_throw;

    /// <summary>
    /// Gets the network-unique identifier for this endpoint.
    /// </summary>
    /// <remarks>
    /// This identifier is unique within the endpoint's network and is consistent across all endpoints in a network. It
    /// is intended to be used as a compact option for titles to refer to specific endpoints in
    /// PartyLocalEndpoint::SendMessage() data buffers without much bandwidth overhead or the need to manually negotiate
    /// identifiers. This identifier is not unique across networks.
    /// <para>
    /// This does not solve the "A talks to B about C before B sees C join" problem. See
    /// PartyManager::SynchronizeMessagesBetweenEndpoints() as a solution for this problem.
    /// </para>
    /// <para>
    /// For local endpoints, this method will fail until the unique identifier is assigned by the transparent cloud
    /// relay. The unique identifier will be assigned when the PartyEndpointCreatedStateChange for this endpoint is
    /// provided via PartyManager::StartProcessingStateChanges(). For remote endpoints, this method will always succeed.
    /// </para>
    /// </remarks>
    /// <param name="uniqueIdentifier">
    /// The output unique identifier.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyEndpointCreatedStateChange" />
    /// <seealso cref="PartyManager::SynchronizeMessagesBetweenEndpoints" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    /// <seealso cref="PartyNetwork::FindEndpointByUniqueIdentifier" />
    PartyError GetUniqueIdentifier(
        _Out_ uint16_t * uniqueIdentifier
        ) const;

    /// <summary>
    /// Gets the value of a shared property.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If there is no property associated with the key, the resulting value will be nullptr. The returned value is only
    /// valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedProperty(
        PartyString key,
        _Outptr_result_maybenull_ const PartyDataBuffer ** value
        ) const party_no_throw;

    /// <summary>
    /// Gets an array of all property keys.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// The returned array is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedPropertyKeys(
        _Out_ uint32_t * propertyCount,
        _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this endpoint object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyEndpoint::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this endpoint object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the endpoint without requiring a mapping lookup. The value is retrieved using the
    /// PartyEndpoint::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the endpoint object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyEndpoint::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyEndpoint() = delete;
    PartyEndpoint(const PartyEndpoint&) = delete;
    PartyEndpoint(PartyEndpoint&&) = delete;
    PartyEndpoint& operator=(const PartyEndpoint&) = delete;
    PartyEndpoint& operator=(PartyEndpoint&&) = delete;
    ~PartyEndpoint() = delete;
};

/// <summary>
/// Represents a local endpoint.
/// </summary>
class PartyLocalEndpoint : public PartyEndpoint
{
public:
    /// <summary>
    /// Gets the local user associated with this local endpoint.
    /// </summary>
    /// <remarks>
    /// If this endpoint is not associated with a user, <paramref name="localUser" /> is set to nullptr.
    /// </remarks>
    /// <param name="localUser">
    /// The output PartyLocalUser.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError GetLocalUser(
        _Outptr_result_maybenull_ PartyLocalUser ** localUser
        ) const party_no_throw;

    /// <summary>
    /// Sends a message to other endpoints in the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Sending messages to local endpoints is not currently supported. If the array of target endpoints includes any
    /// local targets, this call will synchronously fail.
    /// </para>
    /// <para>
    /// All targeted endpoints on a given device will be provided a single PartyStateChangeType::EndpointMessageReceived
    /// state change with every targeted local endpoint provided in the PartyEndpointMessageReceivedStateChange
    /// <em>receiverEndpoints</em> array.
    /// </para>
    /// <para>
    /// If the array of target endpoints is specified as having zero entries, then the message is broadcast to all
    /// remote endpoints currently in the network. A device that receives a broadcast message will have the target
    /// endpoint fields of the PartyEndpointMessageReceivedStateChange populated with all of its local endpoints at the
    /// time the message was received. Due to timing, this may include new endpoints on existing or new devices that
    /// were not yet visible to the sending device at the time it called this function. To guarantee a deterministic set
    /// of target endpoints, explicitly provide that set instead of using a zero entry array.
    /// </para>
    /// <para>
    /// Callers provide 1 or more PartyDataBuffer structures in the <paramref name="dataBuffers" /> array. The memory
    /// that the structures reference does not have to be contiguous, making it easy to have a fixed header buffer
    /// followed by a variable payload, for example. The buffers will be assembled in order, transmitted, and delivered
    /// to the targeted endpoints as a single contiguous data block in a PartyStateChangeType::EndpointMessageReceived
    /// state change. The Party library does not expend bandwidth transmitting metadata to describe the original
    /// PartyDataBuffer segmentation.
    /// </para>
    /// <para>
    /// By default, the buffers described in the caller's <paramref name="dataBuffers" /> array are copied to an
    /// allocated buffer before PartyLocalEndpoint::SendMessage() returns. Specifying
    /// PartySendMessageOptions::DontCopyDataBuffers will avoid this extra copy step and instead require the caller to
    /// keep the memory specified in each buffer valid and unmodified until a PartyStateChangeType::DataBuffersReturned
    /// state change returns ownership of the memory to the caller. The PartyDataBuffer structures themselves do not
    /// need to remain valid after the PartyLocalEndpoint::SendMessage() call returns, only the memory that they
    /// reference.
    /// </para>
    /// <para>
    /// Callers that use PartySendMessageOptions::DontCopyDataBuffers may provide a caller-specific <paramref
    /// name="messageIdentifier" /> context. This pointer-sized value will be included with all
    /// PartyStateChangeType::DataBuffersReturned state changes so that the caller can easily access its own private
    /// message tracking information. The actual value is treated as opaque and is not interpreted by the Party library,
    /// nor transmitted remotely. It's the caller's responsibility to ensure any of its own memory that <paramref
    /// name="messageIdentifier" /> might represent remains valid until the final requested state change associated with
    /// the message and associated <paramref name="messageIdentifier" /> has been processed and returned via
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// <para>
    /// Messages may not be transmitted to target endpoints right away based on factors such as connection quality and
    /// receiver responsiveness. The local send queue will grow if you are sending faster than the connection to an
    /// endpoint is estimated to currently support. This increases memory usage and may result in increases in perceived
    /// message latency, so callers are strongly recommended to monitor and manage the local send queues. You can
    /// retrieve information about the send queue using PartyLocalEndpoint::GetEndpointStatistics(). You can manage the
    /// send queue by reducing the size and/or frequency of sending, by using the <paramref name="queuingConfiguration"
    /// /> optional settings to configure timeouts that automatically expire messages that have been queued for too
    /// long, or by using PartyLocalEndpoint::CancelMessages() to explicitly remove some or all queued messages.
    /// </para>
    /// <para>
    /// The Party library automatically fragments and reassembles large messages that exceed the maximum size supported
    /// by the environment so that callers are not required to manage this. However, there is a small amount of overhead
    /// associated with fragmentation. Callers that are able to send smaller messages or otherwise naturally break up
    /// large state payloads efficiently themselves may wish to do so.
    /// </para>
    /// </remarks>
    /// <param name="targetEndpointCount">
    /// The number of target endpoints in the <paramref name="targetEndpoints" /> array. May be zero to broadcast to all
    /// remote endpoints in the network. A device that receives a broadcast message will have the target endpoint fields
    /// of the PartyEndpointMessageReceivedStateChange populated with all of the device's local endpoints.
    /// </param>
    /// <param name="targetEndpoints">
    /// The <paramref name="targetEndpointCount" /> entry array of target PartyEndpoint object pointers to which the
    /// message should be sent. This is ignored when <paramref name="targetEndpointCount" /> is zero.
    /// </param>
    /// <param name="options">
    /// Zero or more option flags describing how to send the message.
    /// </param>
    /// <param name="queuingConfiguration">
    /// An optional structure describing how the message should behave while locally queued and waiting for an
    /// opportunity to transmit. May be null to use default queuing behavior.
    /// </param>
    /// <param name="dataBufferCount">
    /// The number of buffer structures provided in the <paramref name="dataBuffers" /> array. Must be greater than 0.
    /// </param>
    /// <param name="dataBuffers">
    /// The <paramref name="dataBufferCount" /> entry array of PartyDataBuffer structures describing the message payload
    /// to send.
    /// </param>
    /// <param name="messageIdentifier">
    /// An opaque, caller-specific context pointer the Party library will include in any state changes referring to this
    /// message. It is not interpreted or transmitted remotely. May be null if no message identification context is
    /// needed.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if enqueuing the message for transmission succeeded or an error code otherwise. The
    /// human-readable form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartySendMessageOptions" />
    /// <seealso cref="PartySendMessageQueuingConfiguration" />
    /// <seealso cref="PartyDataBuffersReturnedStateChange" />
    /// <seealso cref="PartyEndpointMessageReceivedStateChange" />
    /// <seealso cref="PartyLocalEndpoint::CancelMessages" />
    /// <seealso cref="PartyLocalEndpoint::GetEndpointStatistics" />
    /// <seealso cref="PartyLocalEndpoint::FlushMessages" />
    PartyError SendMessage(
        uint32_t targetEndpointCount,
        _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
        PartySendMessageOptions options,
        _In_opt_ const PartySendMessageQueuingConfiguration * queuingConfiguration,
        uint32_t dataBufferCount,
        _In_reads_(dataBufferCount) const PartyDataBuffer * dataBuffers,
        _In_opt_ void * messageIdentifier
        ) party_no_throw;

    /// <summary>
    /// Cancels all or a filterable subset of messages previously submitted using PartyLocalEndpoint::SendMessage() that
    /// have not yet started transmitting.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This function is currently unimplemented and will always fail.
    /// </para>
    /// <para>
    /// Matching messages in this local endpoint's send queue to the specified target endpoint(s) that have not started
    /// transmitting will be removed from the queue without being sent.
    /// </para>
    /// <para>
    /// When using PartyCancelMessagesFilterExpression::None for the <paramref name="filterExpression" /> parameter,
    /// PartyLocalEndpoint::CancelMessages() will cancel all messages from this local endpoint to the specified target
    /// endpoints. Callers can instead specify a different PartyCancelMessagesFilterExpression value along with specific
    /// masks and values to match in the <paramref name="messageIdentityFilterMask" /> and <paramref
    /// name="filteredMessageIdentitiesToMatch" /> parameters in order to only match a subset of messages based on how
    /// the filter expressions evaluate the <em>identityForCancelFilters</em> field provided with each message in its
    /// PartySendMessageQueuingConfiguration structure.
    /// </para>
    /// </remarks>
    /// <param name="targetEndpointCount">
    /// The number of target endpoints in the <paramref name="targetEndpoints" /> array. May be 0 to cancel messages to
    /// all endpoints currently in the network, including this local one.
    /// </param>
    /// <param name="targetEndpoints">
    /// The <paramref name="targetEndpointCount" /> entry array of target PartyEndpoint object pointers for which
    /// messages should be canceled. This is ignored when <paramref name="targetEndpointCount" /> is zero.
    /// </param>
    /// <param name="filterExpression">
    /// Zero or more option flags describing how to perform cancelation.
    /// </param>
    /// <param name="messageIdentityFilterMask">
    /// A caller-specific value used to mask bits in messages' identity values.
    /// </param>
    /// <param name="filteredMessageIdentitiesToMatch">
    /// A caller-specific value that must match the result of the filter expression in order for a message to be
    /// selected to be canceled.
    /// </param>
    /// <param name="canceledMessagesCount">
    /// Optional output parameter to receive the number of messages that were actually canceled.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if canceling messages succeeded or an error code otherwise. The human-readable form of the
    /// error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyCancelMessagesFilterExpression" />
    /// <seealso cref="PartySendMessageQueuingConfiguration" />
    /// <seealso cref="PartyLocalEndpoint::SendMessage" />
    PartyError CancelMessages(
        uint32_t targetEndpointCount,
        _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
        PartyCancelMessagesFilterExpression filterExpression,
        uint32_t messageIdentityFilterMask,
        uint32_t filteredMessageIdentitiesToMatch,
        _Out_opt_ uint32_t * canceledMessagesCount
        ) party_no_throw;

    /// <summary>
    /// Forces all queued messages to the specified endpoints from this local endpoint to be sent as soon as possible
    /// regardless of their coalesce settings.
    /// </summary>
    /// <remarks>
    /// <para>
    /// When PartySendMessageOptions::CoalesceOpportunistically or PartySendMessageOptions::AlwaysCoalesceUntilFlushed
    /// is specified in a call to PartyLocalEndpoint::SendMessage(), the message may not be transmitted immediately and
    /// instead be combined with other messages. This coalescing can improve bandwidth efficiency at the potential
    /// expense of perceived latency. This function allows the title to manually force such coalesced messages to begin
    /// transmitting as soon as possible.
    /// </para>
    /// <para>
    /// Currently this function ignores the <paramref name="targetEndpoints" /> parameter and forces all queued messages from this
    /// local endpoint to be transmitted as soon as possible.
    /// </para>
    /// </remarks>
    /// <param name="targetEndpointCount">
    /// This parameter is currently ignored. The number of target endpoints in the <paramref name="targetEndpoints" /> array.
    /// </param>
    /// <param name="targetEndpoints">
    /// This parameter is currently ignored. A <paramref name="targetEndpointCount" /> entry array of target PartyEndpoint object pointers. Messages from
    /// this local endpoint, up through and including the most recent message to any endpoint in the array, will be
    /// transmitted as soon as possible.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if flushing messages succeeded or an error code otherwise. The human-readable form of the
    /// error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalEndpoint::SendMessage" />
    /// <seealso cref="PartySendMessageOptions::CoalesceOpportunistically" />
    /// <seealso cref="PartySendMessageOptions::AlwaysCoalesceUntilFlushed" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError FlushMessages(
        uint32_t targetEndpointCount,
        _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints
        ) party_no_throw;

    /// <summary>
    /// Gets one or more statistic counter values for the specified target endpoints.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This function is used to retrieve performance counters, queue lengths, historical usage metrics, or other
    /// statistical information recorded between this local endpoint and a target endpoint.
    /// </para>
    /// <para>
    /// Alternatively, multiple target endpoints can be provided, or a zero-entry array to retrieve statistics for all
    /// target endpoints currently in the network, including this local one. If multiple target endpoints are requested,
    /// then the values returned are the combined statistics for those endpoints. The particular method used to combine
    /// multiple endpoint statistics into a single value depends on and is described by the specific
    /// PartyEndpointStatistic type.
    /// </para>
    /// <para>
    /// A given PartyEndpointStatistic type may appear in any order in the <paramref name="statisticTypes" /> array, but
    /// must not be specified more than once. Each corresponding statistic value will be written to the <paramref
    /// name="statisticValues" /> array in the same order.
    /// </para>
    /// <para>
    /// The returned statistic values are always the most current ones available. There is no guarantee they will report
    /// the same value from one GetEndpointStatistics() call to the next, even if there were no intervening calls to
    /// PartyManager::StartProcessingStateChanges() or PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="targetEndpointCount">
    /// The number of target endpoints in the <paramref name="targetEndpoints" /> array. May be 0 to retrieve statistics
    /// for all endpoints currently in the network, including this local one.
    /// </param>
    /// <param name="targetEndpoints">
    /// The <paramref name="targetEndpointCount" /> entry array of target PartyEndpoint object pointers for which
    /// statistics should be retrieved. This is ignored when <paramref name="targetEndpointCount" /> is zero.
    /// </param>
    /// <param name="statisticCount">
    /// The number of statistics in the input <paramref name="statisticTypes" /> array and to be written in the
    /// <paramref name="statisticValues" /> output array. This must be at least 1.
    /// </param>
    /// <param name="statisticTypes">
    /// The <paramref name="statisticCount" /> entry input array of unique PartyEndpointStatistic types to retrieve.
    /// </param>
    /// <param name="statisticValues">
    /// The <paramref name="statisticCount" /> entry output array where the statistic values should be written. Each
    /// statistic value will be written at the same entry index corresponding to where the requested
    /// PartyEndpointStatistic appears in the <paramref name="statisticTypes" /> input array.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the endpoint statistics succeeded or an error code otherwise. The
    /// human-readable form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyEndpointStatistic" />
    /// <seealso cref="PartyNetwork::GetNetworkStatistics" />
    PartyError GetEndpointStatistics(
        uint32_t targetEndpointCount,
        _In_reads_(targetEndpointCount) PartyEndpointArray targetEndpoints,
        uint32_t statisticCount,
        _In_reads_(statisticCount) const PartyEndpointStatistic * statisticTypes,
        _Out_writes_all_(statisticCount) uint64_t * statisticValues
        ) const party_no_throw;

    /// <summary>
    /// Sets or removes multiple shared properties associated with this object.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If a nullptr value is passed in the array, the corresponding key will be removed. Existing properties not
    /// specified in the call will remain unchanged.
    /// </para>
    /// </remarks>
    PartyError SetSharedProperties(
        uint32_t propertyCount,
        _In_reads_(propertyCount) const PartyString * keys,
        _In_reads_(propertyCount) const PartyDataBuffer * values
        ) party_no_throw;

private:
    PartyLocalEndpoint() = delete;
    PartyLocalEndpoint(const PartyLocalEndpoint&) = delete;
    PartyLocalEndpoint(PartyLocalEndpoint&&) = delete;
    PartyLocalEndpoint& operator=(const PartyLocalEndpoint&) = delete;
    PartyLocalEndpoint& operator=(PartyLocalEndpoint&&) = delete;
    ~PartyLocalEndpoint() = delete;
};

/// <summary>
/// Represents a device across networks.
/// </summary>
class PartyDevice
{
public:
    /// <summary>
    /// Gets the PartyLocalDevice version of this device.
    /// </summary>
    /// <remarks>
    /// If this device is not the local device, nullptr is returned.
    /// </remarks>
    PartyError GetLocal(
        _Outptr_result_maybenull_ PartyLocalDevice ** localDevice
        ) const party_no_throw;

    /// <summary>
    /// Gets the chat controls on this device.
    /// </summary>
    /// <remarks>
    /// The memory for the returned array is invalidated whenever the title calls
    /// PartyManager::StartProcessingStateChanges(). If this is the local device, the memory for the array is also
    /// invalidated when PartyLocalDevice::CreateChatControl() returns success.
    /// </remarks>
    PartyError GetChatControls(
        _Out_ uint32_t * chatControlCount,
        _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
        ) const party_no_throw;

    /// <summary>
    /// Gets the value of a shared property.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If there is no property associated with the key, the resulting value will be nullptr. The returned value is only
    /// valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedProperty(
        PartyString key,
        _Outptr_result_maybenull_ const PartyDataBuffer ** value
        ) const party_no_throw;

    /// <summary>
    /// Gets an array of all property keys.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// The returned array is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedPropertyKeys(
        _Out_ uint32_t * propertyCount,
        _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this device object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyDevice::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this device object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the device without requiring a mapping lookup. The value is retrieved using the
    /// PartyDevice::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the device object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyDevice::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyDevice() = delete;
    PartyDevice(const PartyDevice&) = delete;
    PartyDevice(PartyDevice&&) = delete;
    PartyDevice& operator=(const PartyDevice&) = delete;
    PartyDevice& operator=(PartyDevice&&) = delete;
    ~PartyDevice() = delete;
};

/// <summary>
/// Represents the local device.
/// </summary>
/// <seealso cref="PartyManager::GetLocalDevice" />
class PartyLocalDevice : public PartyDevice
{
public:
    /// <summary>
    /// Creates a local chat control for the specified user.
    /// </summary>
    /// <remarks>
    /// If this method returns success, a PartyCreateChatControlCompletedStateChange state change will be generated to
    /// provide the result of the asynchronous operation. If the asynchronous operation succeeds, a
    /// PartyChatControlCreatedStateChange will be generated. If the operation fails, a
    /// PartyChatControlDestroyedStateChange will be generated. This method itself does not make the chat control
    /// visible to any remote devices. To announce this chat control to remote devices, the title should call
    /// PartyNetwork::ConnectChatControl.
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyManager::GetChatControls() or PartyDevice::GetChatControls() for the local device, as it synchronously
    /// adds the new chat control to the arrays. PartyManager::StartProcessingStateChanges() also invalidates the
    /// memory for these arrays.
    /// </para>
    /// <para>
    /// The language associated with this chat control can optionally be specified via the <paramref
    /// name="languageCode" /> parameter. If no language is specified, the user's default, as determined by the
    /// platform, will be used. The language is used as the spoken the language associated with this chat control for
    /// transcription and the target language for incoming translations. If the language code specified is en-US, for
    /// instance, the input audio to this chat control will be treated as the English (United
    /// States) language and transcribed as such. If translation is enabled via either
    /// PartyLocalChatControl::SetVoiceChatTranscriptionOptions() or PartyLocalChatControl::SetTextChatOptions(), the
    /// incoming voice chat transcriptions and/or text chat will be translated to English (United States).
    /// </para>
    /// <para>
    /// The language code should be in BCP 47 format; supported language codes are enumerated at
    /// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support. Specifying an
    /// unsupported or invalid language code will not cause this method to fail, but will result in failure to
    /// generate transcriptions associated with this chat control. The language code used with this method can be
    /// queried via PartyLocalChatControl::GetLanguage(). It can be modified via PartyLocalChatControl::SetLanguage().
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyCreateChatControlCompletedStateChange" />
    /// <seealso cref="PartyChatControlCreatedStateChange" />
    /// <seealso cref="PartyChatControlDestroyedStateChange" />
    /// <seealso cref="PartyManager::GetChatControls" />
    /// <seealso cref="PartyDevice::GetChatControls" />
    /// <seealso cref="PartyNetwork::ConnectChatControl" />
    /// <seealso cref="PartyLocalChatControl::GetLanguage" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    /// <seealso cref="PartyLocalChatControl::SetVoiceChatTranscriptionOptions" />
    /// <seealso cref="PartyLocalChatControl::SetTextChatTranscriptionOptions" />
    PartyError CreateChatControl(
        const PartyLocalUser * localUser,
        _In_opt_ PartyString languageCode,
        _In_opt_ void * asyncIdentifier,
        _Outptr_opt_ PartyLocalChatControl ** localChatControl
        ) party_no_throw;

    /// <summary>
    /// Destroys a local chat control.
    /// </summary>
    /// <seealso cref="PartyDestroyChatControlCompletedStateChange" />
    /// <seealso cref="PartyChatControlDestroyedStateChange" />
    PartyError DestroyChatControl(
        _In_ PartyLocalChatControl * localChatControl,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Sets or removes multiple shared properties associated with this object.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If a nullptr value is passed in the array, the corresponding key will be removed. Existing properties not
    /// specified in the call will remain unchanged.
    /// </para>
    /// </remarks>
    PartyError SetSharedProperties(
        uint32_t propertyCount,
        _In_reads_(propertyCount) const PartyString * keys,
        _In_reads_(propertyCount) const PartyDataBuffer * values
        ) party_no_throw;

private:
    PartyLocalDevice() = delete;
    PartyLocalDevice(const PartyLocalDevice&) = delete;
    PartyLocalDevice(PartyLocalDevice&&) = delete;
    PartyLocalDevice& operator=(const PartyLocalDevice&) = delete;
    PartyLocalDevice& operator=(PartyLocalDevice&&) = delete;
    ~PartyLocalDevice() = delete;
};

/// <summary>
/// Represents an invitation to authenticate into a network via PartyNetwork::AuthenticateLocalUser().
/// </summary>
/// <seealso cref="PartyManager::CreateNewNetwork" />
/// <seealso cref="PartyNetwork::CreateInvitation" />
/// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
/// <seealso cref="PartyInvitationConfiguration" />
class PartyInvitation
{
public:
    /// <summary>
    /// Gets the PlayFab Entity ID of the user that created this invitation or null if this invitation was generated as
    /// part of a PartyManager::CreateNewNetwork() operation.
    /// </summary>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    PartyError GetCreatorEntityId(
        _Outptr_result_maybenull_ PartyString * entityId
        ) const party_no_throw;

    /// <summary>
    /// Gets this invitation's configuration.
    /// </summary>
    /// <remarks>
    /// The memory for the PartyInvitationConfiguration and all memory it references are valid for the lifetime of the
    /// invitation object.
    /// </remarks>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyInvitationConfiguration" />
    PartyError GetInvitationConfiguration(
        _Outptr_ const PartyInvitationConfiguration ** configuration
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this invitation
    /// object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyInvitation::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this invitation object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the invitation without requiring a mapping lookup. The value is retrieved using the
    /// PartyInvitation::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the invitation object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyInvitation::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyInvitation() = delete;
    PartyInvitation(const PartyInvitation&) = delete;
    PartyInvitation(PartyInvitation&&) = delete;
    PartyInvitation& operator=(const PartyInvitation&) = delete;
    PartyInvitation& operator=(PartyInvitation&&) = delete;
    ~PartyInvitation() = delete;
};

/// <summary>
/// Represents a network.
/// </summary>
class PartyNetwork
{
public:
    /// <summary>
    /// Queues an asynchronous operation to authenticate the specified local user into the network.
    /// </summary>
    /// <remarks>
    /// While any device with the appropriate network descriptor can establish a connection to the network, no useful
    /// actions can be performed, and no useful information can be gleaned, without first authenticating a local user on
    /// the device into the network. As such, authentication is an important security measure to ensure the integrity of
    /// the network and the privacy of the devices and users participating in the network. To authenticate a user is to
    /// have the transparent cloud relay server validate the user's identity and that the user is allowed to join the
    /// network.
    /// <para>
    /// Upon successful completion of the asynchronous operation started by this call, a user is considered
    /// authenticated into the network. Completion is indicated by the PartyAuthenticateLocalUserCompletedStateChange.
    /// Successful authentication requires that the local user's PlayFab Entity Token is valid and is associated with
    /// the local user's PlayFab Entity ID. Successful authentication also requires that the provided invitation allows
    /// the provided local user to join the network. Authentication will fail if authenticating the provided user would
    /// violate one of the limits in the network's configuration. These requirements are enforced by the transparent
    /// cloud relay server. If the asynchronous operation fails, the PartyAuthenticateLocalUserCompletedStateChange will
    /// provide a diagnostic result and error detail, and a PartyLocalUserRemovedStateChange will be generated. Because
    /// being connected to a network with no authenticated users is not a useful state outside of transition periods,
    /// the Party library will automatically disconnect a device that does not have an authenticated user for an
    /// extended period.
    /// </para>
    /// <para>
    /// Users need an <paramref name="invitationIdentifier" /> to call this method and authenticate into the network.
    /// Most commonly this means that another device will have to share the identifier of the initial invitation
    /// generated via PartyManager::CreateNewNetwork() or share the identifier of an invitation it has generated via
    /// PartyNetwork::CreateInvitation().
    /// </para>
    /// <para>
    /// User authentication also determines device authentication. A device is considered authenticated into the network
    /// if at least one local user is authenticated into the network. If a device is authenticated into the network, it
    /// will be visible to all other authenticated devices. If a device is connected to the network but not
    /// authenticated, no remote devices, endpoints, or chat controls, will be visible. Similarly, the device will not
    /// be visible to any other devices connected to the network.
    /// </para>
    /// <para>
    /// Once this function is called, all other functions that queue asynchronous operations but require the local user
    /// or local device to be authenticated into the network can be called. Such operations will be queued until
    /// completion of the authentication operation. Once the authentication operation completes, the queued operations
    /// will be processed. If the authentication operation failed, the queued operations will also fail and their
    /// respective completion state changes will indicate such.
    /// </para>
    /// <para>
    /// If the local device enters a state in which there are no authenticated users and no authentication operations
    /// in progress, then all endpoints, including those that are not fully created, will be destroyed automatically.
    /// This will be signaled by PartyEndpointDestroyedStateChanges.
    /// </para>
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyNetwork::GetLocalUsers(), as it synchronously adds the new user to the array.
    /// PartyManager::StartProcessingStateChanges() also invalidates the memory for the array.
    /// </para>
    /// <para>
    /// This function will fail if the specified <paramref name="localUser" /> is in the process of authenticating into
    /// the network, is already authenticated into the network, is authenticated but in the process of being removed due
    /// to a previous call to PartyNetwork::RemoveLocalUser(), or if the device overall is in the process of becoming
    /// unauthenticated due to its last authenticated user being removed from the network.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user to authenticate into the network.
    /// </param>
    /// <param name="invitationIdentifier">
    /// The identifier of the invitation that allows the <paramref name="localUser" /> to authenticate into the network.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyAuthenticateLocalUserCompletedStateChange" />
    /// <seealso cref="PartyEndpointDestroyedStateChange" />
    /// <seealso cref="PartyLocalUserRemovedStateChange" />
    /// <seealso cref="PartyNetworkConfiguration" />
    /// <seealso cref="PartyManager::CreateLocalUser" />
    /// <seealso cref="PartyNetwork::RemoveLocalUser" />
    /// <seealso cref="PartyNetwork::GetLocalUsers" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyInvitation::GetIdentifier" />
    PartyError AuthenticateLocalUser(
        const PartyLocalUser * localUser,
        PartyString invitationIdentifier,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous operation to remove a local user from the network.
    /// </summary>
    /// <remarks>
    /// Upon successful completion of the asynchronous operation, a user is no longer considered authenticated into the
    /// network. Completion is indicated by a PartyRemoveLocalUserCompletedStateChange. If the asynchronous operation
    /// succeeds, a PartyLocalUserRemovedStateChange will be provided before the
    /// PartyRemoveLocalUserCompletedStateChange. Prior to the removal of a local user, all endpoints associated with
    /// that user are destroyed and all chat controls associated with that user will be disconnected from the network.
    /// Each endpoint destruction and chat control disconnection will be indicated by a
    /// PartyEndpointDestroyedStateChange or PartyChatControlLeftNetworkStateChange, respectively.
    /// <para>
    /// When all local users are removed from the network, the device is no longer considered authenticated. All
    /// endpoints are destroyed and all remote devices will appear to leave the network, because they are no longer
    /// visible to the local device. Similarly, all remote devices will see the local device as having left the network.
    /// The device will not immediately be disconnected and can again be authenticated by a new call to
    /// PartyNetwork::AuthenticateLocalUser(). However, because being connected to a network with no authenticated users
    /// is not a useful state outside of transition periods, the Party library will automatically disconnect a device
    /// that is unauthenticated for more than one minute.
    /// </para>
    /// <para>
    /// This function will fail if the specified <paramref name="localUser" /> is already in the process of being
    /// removed from the network due to a previous call to PartyNetwork::RemoveLocalUser().
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user to remove from the network.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyRemoveLocalUserCompletedStateChange" />
    /// <seealso cref="PartyEndpointDestroyedStateChange" />
    /// <seealso cref="PartyChatControlLeftNetworkStateChange" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::GetLocalUsers" />
    PartyError RemoveLocalUser(
        const PartyLocalUser * localUser,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to create an invitation for the network.
    /// </summary>
    /// <remarks>
    /// To join a network, a user must provide an invitation to PartyNetwork::AuthenticateLocalUser().
    /// <para>
    /// This function queues an asynchronous attempt to create an invitation for the network. A
    /// PartyCreateInvitationCompletedStateChange will be provided upon completion of the asynchronous operation,
    /// indicating success or failure. On success, a PartyInvitationCreatedStateChange will have been generated
    /// beforehand to indicate that the transparent cloud relay server is ready to accept authentications using the
    /// invitation's identifier. On failure, a PartyInvitationDestroyedStateChange will have been generated beforehand
    /// to indicate that the invitation object is no longer valid and will no longer be queryable via
    /// PartyNetwork::GetInvitations().
    /// </para>
    /// <para>
    /// The lifetime of the invitation is tied to the owning local user's membership in the network, therefore
    /// <paramref name="localUser" /> must be authenticated or in the process of authenticating. If
    /// <paramref name="localUser" /> leaves the network for any reason the invitation will be automatically revoked and
    /// subsequent attempts to use that invitation's identifier to join the network will fail until a new invitation is
    /// created using that identifier.
    /// </para>
    /// <para>
    /// Invitations created with this method will only be queryable via PartyNetwork::GetInvitations() on the local
    /// device where the invitation was created.
    /// </para>
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyNetwork::GetInvitations(), as it synchronously adds the new invitation to the array.
    /// PartyManager::StartProcessingStateChanges() also invalidates the memory for the array.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user that owns the invitation in the network. If this local user leaves the network for any reason the
    /// invitation will be automatically revoked.
    /// </param>
    /// <param name="invitationConfiguration">
    /// An optionally specified configuration for the newly created invitation.
    /// <para>
    /// If this value is null, the default configuration values will be used. By default, PlayFab Party will generate a
    /// unique invitation identifier for the title, the revocability will be PartyInvitationRevocability::Creator, and
    /// the PlayFab Entity ID list will be empty, allowing any user to join using the invitation.
    /// </para>
    /// <para>
    /// If a configuration is provided, the title may optionally specify the identifier on the configuration. If the
    /// identifier is null or an empty string, the PlayFab Party library will generate an identifier for the title. It
    /// is guaranteed that this generated identifer will be different from all identifiers that the PlayFab Party
    /// library has already generated for invitations on this network across all devices. Titles may specify their own
    /// identifier by providing a non-null, non-empty value in the configuration. If the title specifies the identifier,
    /// it is the title's responsibility to ensure that this identifier does not collide with the identifiers of other
    /// invitations created on this network via PartyManager::CreateNewNetwork() or PartyNetwork::CreateInvitation() on
    /// any device. If the title attempts to create an invitation with an identifer that would collide with a
    /// pre-existing invitation, then the operation will fail asynchronously and the title will receive a
    /// PartyInvitationDestroyedStateChange followed by a PartyCreateInvitationCompletedStateChange with a failure
    /// result.
    /// </para>
    /// <para>
    /// If a configuration is provided, its revocability must be PartyInvitationRevocability::Creator.
    /// </para>
    /// <para>
    /// If a configuration is provided and the list of PlayFab Entity IDs is empty, all users will be allowed to join
    /// using the new invitation.
    /// </para>
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <param name="invitation">
    /// An optional, output invitation that may immediately be used to queue user authentications on a network via
    /// PartyNetwork::AuthenticateLocalUser().
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyInvitationDestroyedStateChange" />
    /// <seealso cref="PartyCreateInvitationCompletedStateChange" />
    PartyError CreateInvitation(
        const PartyLocalUser * localUser,
        _In_opt_ const PartyInvitationConfiguration * invitationConfiguration,
        void* asyncIdentifier,
        _Outptr_opt_ PartyInvitation ** invitation
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to revoke an invitation from the network.
    /// </summary>
    /// <remarks>
    /// Titles may revoke an invitation to prevent further users from authenticating into a network using the
    /// invitation's identifier.
    /// <para>
    /// This function queues an asynchronous attempt to revoke an invitation from the network. A
    /// PartyRevokeInvitationCompletedStateChange will be provided upon completion of the asynchronous operation,
    /// indicating success or failure. On success, a PartyInvitationDestroyedStateChange will have been generated
    /// beforehand with PartyDestroyedReason::Requested, to indicate that the network will no longer accept
    /// authentications using the invitation's identifier until a new invitation is created with that same identifier.
    /// It also indicates that the invitation will no longer be queryable via PartyNetwork::GetInvitations().
    /// </para>
    /// <para>
    /// This operation will only succeed if the invitation was created with its revocability specified such that the
    /// <paramref name="localUser" /> on the local device may revoke the invitation. This might not be the case if the
    /// revocability is set to PartyInvitationRevocability::Creator and the <paramref name="localUser" /> is
    /// authenticated on a different device than the creator or if the <paramref name="localUser" /> refers to a
    /// different user than the creator.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user attempting to revoke the invitation.
    /// </param>
    /// <param name="invitation">
    /// The invitation to revoke.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyRevokeInvitationCompletedStateChange" />
    /// <seealso cref="PartyInvitationDestroyedStateChange" />
    PartyError RevokeInvitation(
        const PartyLocalUser * localUser,
        PartyInvitation * invitation,
        void* asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets an array containing all invitations exposed to the local device.
    /// </summary>
    /// <remarks>
    /// The array is backed by the library's internal memory. The array is only valid until the next call to either
    /// PartyNetwork::CreateInvitation() or PartyManager::StartProcessingStateChanges().
    /// <para>
    /// A new invitation is exposed to the local device whenever the local device calls PartyNetwork::CreateInvitation()
    /// or a PartyInvitationCreatedStateChange is provided via PartyManager::StartProcessingStateChanges().
    /// </para>
    /// <para>
    /// Invitations created via PartyNetwork::CreateInvitation() will only be exposed to the local device. The initial
    /// invitation will be exposed to all devices in the network via a PartyInvitationCreatedStateChange.
    /// </para>
    /// <para>
    /// An invitation will no longer be exposed to the local device whenever a PartyInvitationDestroyedStateChange is
    /// provided via PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="invitationCount">
    /// An output value indicating the number of invitations provided in <paramref name="invitations" />.
    /// </param>
    /// <param name="invitations">
    /// An output array, backed by the library's internal memory, containing the list of invitations that have been
    /// created for the network.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyNetwork::RevokeInvitation" />
    /// <seealso cref="PartyInvitationCreatedStateChange" />
    /// <seealso cref="PartyInvitationDestroyedStateChange" />
    PartyError GetInvitations(
        _Out_ uint32_t* invitationCount,
        _Outptr_result_buffer_(*invitationCount) PartyInvitationArray * invitations
        ) const party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to create a local endpoint.
    /// </summary>
    /// <remarks>
    /// This function queues an asynchronous attempt to create an endpoint associated with the local device on this
    /// network. A PartyCreateEndpointCompletedStateChange will be provided upon completion of the operation, indicating
    /// success or failure. On success, a PartyEndpointCreatedStateChange will be generated, and the endpoint will be
    /// fully created, connected to the network, and visible to all authenticated devices in the network. On failure, a
    /// PartyEndpointDestroyedStateChange will be generated.
    /// <para>
    /// This function optionally provides <paramref name="localEndpoint" /> as output that can immediately be used to
    /// perform asynchronous endpoint operations, such as PartyLocalEndpoint::SendMessage() and
    /// PartyLocalEndpoint::SetSharedProperties(). These asynchronous operations will be internally queued until the
    /// endpoint creation completes, at which point they will be processed. PartyEndpoint::GetUniqueIdentifier() will
    /// return a failure until the endpoint creation completes. This <paramref name="localEndpoint" /> will also be
    /// provided in the resulting PartyCreateEndpointCompletedStateChange.
    /// </para>
    /// <para>
    /// A local user may optionally be provided as the owner of an endpoint. If an owning local user is provided, it
    /// must be authenticated into the network or in the process of authenticating into the network. If its
    /// authentication fails, the endpoint creation will consequently fail as well. If the owning local user is removed
    /// from the network while this endpoint exists, the endpoint will be automatically destroyed. This will be signaled
    /// via a PartyEndpointDestroyedStateChange.
    /// </para>
    /// <para>
    /// If the local device enters a state in which there are no authenticated users and no authentication operations
    /// in progress, then all endpoints, including those that are not fully created, will be destroyed automatically.
    /// This will be signaled by PartyEndpointDestroyedStateChanges.
    /// </para>
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyNetwork::GetEndpoints(), as it synchronously adds the new endpoint to the array.
    /// PartyManager::StartProcessingStateChanges() also invalidates the memory for the array.
    /// </para>
    /// <para>
    /// The property bag is a collection of title-specific values associated with an endpoint. The initial property bag
    /// is queryable as soon as the endpoint becomes visible.
    /// </para>
    /// <para>
    /// The property bag is currently unimplemented. <paramref name="propertyCount" /> must be zero and both <paramref
    /// name="keys" /> and <paramref name="values" /> must be nullptr.
    /// </para>
    /// <para>
    /// If a client would violate the PartyNetworkConfiguration::maxEndpointsPerDeviceCount limit by calling this method
    /// after the network configuration was made available, this operation will fail synchronously. If the client
    /// queues a violating number of endpoint creations before the network configuration becomes available, the client
    /// will be kicked from the network and a PartyNetworkDestroyedStateChange will be generated when the network
    /// configuration becomes available.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// An optional local user to associate as the owner of this endpoint. When this endpoint becomes visible on remote
    /// devices, the user's identifier will be tied to this endpoint. The endpoint will be destroyed if the user becomes
    /// unauthenticated because they were voluntarily removed via PartyNetwork::RemoveLocalUser() or kicked via
    /// PartyNetwork::KickUser().
    /// </param>
    /// <param name="propertyCount">
    /// The number of properties in the input <paramref name="keys" /> and <paramref name="values" /> arrays. Property
    /// bags are currently unimplemented. This parameter must be zero.
    /// </param>
    /// <param name="keys">
    /// The <paramref name="propertyCount" /> entry array of property bag keys. The nth key in this array maps to the
    /// nth value in the <paramref name="values" /> array. Property bags are currently unimplemented. This parameter
    /// must be nullptr.
    /// </param>
    /// <param name="values">
    /// The <paramref name="propertyCount" /> entry array of property bag values. The nth value in this array is mapped
    /// by the nth key in the <paramref name="keys" /> array. Property bags are currently unimplemented. This parameter
    /// must be nullptr.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <param name="localEndpoint">
    /// An optional, output local endpoint object on which to queue endpoint operations.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the asynchronous operation to create the endpoint began, or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyCreateEndpointCompletedStateChange" />
    /// <seealso cref="PartyEndpointCreatedStateChange" />
    /// <seealso cref="PartyEndpointDestroyedStateChange" />
    /// <seealso cref="PartyNetworkDestroyedStateChange" />
    /// <seealso cref="PartyNetworkConfiguration" />
    /// <seealso cref="PartyNetwork::GetEndpoints" />
    /// <seealso cref="PartyNetwork::CreateEndpoint" />
    /// <seealso cref="PartyLocalEndpoint::SendMessage" />
    /// <seealso cref="PartyLocalEndpoint::SetSharedProperties" />
    /// <seealso cref="PartyEndpoint::GetUniqueIdentifier" />
    /// <seealso cref="PartyEndpoint::GetEntityId" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::RemoveLocalUser" />
    /// <seealso cref="PartyNetwork::KickUser" />
    PartyError CreateEndpoint(
        _In_opt_ const PartyLocalUser * localUser,
        uint32_t propertyCount,
        _In_reads_opt_(propertyCount) const PartyString * keys,
        _In_reads_opt_(propertyCount) const PartyDataBuffer * values,
        _In_opt_ void * asyncIdentifier,
        _Outptr_opt_ PartyLocalEndpoint ** localEndpoint
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to destroy a local endpoint.
    /// </summary>
    /// <remarks>
    /// This function queues an asynchronous attempt to destroy an endpoint associated with the local device on this
    /// network. A PartyDestroyEndpointCompletedStateChange will be provided upon completion of the operation,
    /// indicating success or failure. On success, the endpoint is no longer connected to the network or visible to any
    /// devices. Memory for the endpoint will remain valid until all state changes referencing the endpoint have been
    /// returned to PartyManager::FinishProcessingStateChanges().
    /// <para>
    /// If this call returns success, asynchronous endpoint destruction has begun and methods that require network
    /// connectivity, such as PartyLocalEndpoint::SendMessage(), will fail. Methods that retrieve cached state, such as
    /// PartyEndpoint::GetCustomContext() and PartyEndpoint::GetEntityId(), will continue to succeed.
    /// </para>
    /// <para>
    /// When the local device begins destroying an endpoint, every remote device will be alerted via a
    /// PartyEndpointDestroyedStateChange. Those remote devices have the opportunity to send the destructing endpoint
    /// any final messages they wish before returning the PartyEndpointDestroyedStateChange to
    /// PartyManager::FinishProcessingStateChanges(). By returning the PartyEndpointDestroyedStateChange, the remote
    /// device acknowledges the endpoint's destruction and may no longer target the endpoint in
    /// PartyLocalEndpoint::SendMessage() calls. Because the endpoint will not be able to complete its destruction on
    /// the local device until all remote devices have acknowledged it, it is recommended to return this state change as
    /// quickly as possible. If the remote device does not return the PartyEndpointDestroyedStateChange within two
    /// seconds, the remote device will automatically acknowledge the endpoint destruction and the endpoint will no
    /// longer be targetable in PartyLocalEndpoint::SendMessage() calls. The destructing endpoint can receive
    /// PartyEndpointMessageReceivedStateChanges up until all remote devices have acknowledged the endpoint's
    /// destruction, which is indicated by the local device seeing a PartyEndpointDestroyedStateChange.
    /// </para>
    /// </remarks>
    /// <param name="localEndpoint">
    /// The local endpoint to begin destroying.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the asynchronous operation to destroy the endpoint began, or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyDestroyEndpointCompletedStateChange" />
    /// <seealso cref="PartyEndpointDestroyedStateChange" />
    /// <seealso cref="PartyEndpointMessageReceivedStateChange" />
    /// <seealso cref="PartyManager::FinishProcessingStateChanges" />
    /// <seealso cref="PartyLocalEndpoint::SendMessage" />
    /// <seealso cref="PartyEndpoint::GetCustomContext" />
    /// <seealso cref="PartyLocalEndpoint::GetEntityId" />
    PartyError DestroyEndpoint(
        _In_ PartyLocalEndpoint * localEndpoint,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Leaves the network.
    /// </summary>
    PartyError LeaveNetwork(
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the endpoints in this network.
    /// </summary>
    /// <remarks>
    /// This function gets all endpoints currently associated with the network and visible to the local device.
    /// <para>
    /// All local endpoints that have successfully been created or are in the process of being created will be present
    /// in <paramref name="endpoints" />.
    /// </para>
    /// <para>
    /// Only remote endpoints that have successfully been created in the network and are visible to the local device
    /// will be present in <paramref name="endpoints" />.
    /// </para>
    /// <para>
    /// The memory for the returned array is invalidated whenever the title calls
    /// PartyManager::StartProcessingStateChanges() or PartyNetwork::CreateEndpoint() returns success.
    /// </para>
    /// </remarks>
    /// <param name="endpointCount">
    /// The output number of PartyEndpoint entries in the <paramref name="endpoints" /> array.
    /// </param>
    /// <param name="endpoints">
    /// An output array, backed by the library's internal memory, containing the list of endpoints.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyEndpointCreatedStateChange" />
    /// <seealso cref="PartyNetwork::CreateEndpoint" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    PartyError GetEndpoints(
        _Out_ uint32_t * endpointCount,
        _Outptr_result_buffer_(*endpointCount) PartyEndpointArray * endpoints
        ) const party_no_throw;

    /// <summary>
    /// Finds the endpoint with the corresponding network-unique identifier in this network, if it exists.
    /// </summary>
    /// <param name="uniqueIdentifier">
    /// The network-unique identifier of an endpoint.
    /// </param>
    /// <param name="endpoint">
    /// The output endpoint with a network-unique identifier matching <paramref name="uniqueIdentifier" />.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if an endpoint with a matching identifier was found on this network or an error code
    /// otherwise.
    /// </returns>
    /// <seealso cref="PartyEndpoint::GetUniqueIdentifier" />
    PartyError FindEndpointByUniqueIdentifier(
        uint16_t uniqueIdentifier,
        _Outptr_ PartyEndpoint ** endpoint
        ) const party_no_throw;

    /// <summary>
    /// Gets the devices in this network.
    /// </summary>
    /// <remarks>
    /// The memory for the returned array is invalidated whenever the title calls
    /// PartyManager::StartProcessingStateChanges(). The local device is always in the array.
    /// </remarks>
    PartyError GetDevices(
        _Out_ uint32_t * deviceCount,
        _Outptr_result_buffer_(*deviceCount) PartyDeviceArray * devices
        ) const party_no_throw;

    /// <summary>
    /// Gets an array containing the local users that are authenticated into the network.
    /// </summary>
    /// <remarks>
    /// The array is backed by the library's internal memory. The array is only valid until the next call to either
    /// PartyNetwork::AuthenticateLocalUser() or PartyManager::StartProcessingStateChanges(). The individual local user
    /// objects are valid until the local user's PartyDestroyLocalUserCompletedStateChange is reported and all state
    /// changes referencing the local user object are returned via PartyManager::FinishProcessingStateChanges().
    /// </remarks>
    /// <param name="userCount">
    /// An output value indicating the number of users provided in <paramref name="localUsers" />.
    /// </param>
    /// <param name="localUsers">
    /// An output array, backed by the library's internal memory, containing the list of users that are authenticated
    /// into the network.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::RemoveLocalUser" />
    PartyError GetLocalUsers(
        _Out_ uint32_t * userCount,
        _Outptr_result_buffer_(*userCount) PartyLocalUserArray * localUsers
        ) const party_no_throw;

    /// <summary>
    /// Gets the network descriptor for this network.
    /// </summary>
    /// <remarks>
    /// A network descriptor contains all the information required for a device to connect to the network to which the
    /// descriptor is associated. PartyManager::SerializeNetworkDescriptor() can be used to get the serialized form of
    /// the descriptor, which is safe to exchange over title and platform-specific communication channels. However, the
    /// network descriptor provided by this call is not serializable until the asynchronous creation operation
    /// associated with this network successfully completes, signaled by a PartyCreateNewNetworkCompletedStateChange
    /// with a success result code.
    /// <para>
    /// PartyNetworkDescriptors work in tandem with PartyInvitations to facilitate inviting remote users to join the
    /// network. First, obtain the network descriptor via PartyNetwork::GetNetworkDescriptor() and serialize it via
    /// PartyManager::SerializeNetworkDescriptor(). Next, create an invitation via PartyNetwork::CreateInvitation() or
    /// query for a preexisting invitation via PartyNetwork::GetInvitations() and obtain the invitation's identifier
    /// from its configuration via PartyInvitation::GetInvitationConfiguration(). Last, include both the serialized
    /// network descriptor and the invitation identifier in the payload of the platform-specific invite mechanism. When
    /// the remote user receives the invite, they deserialize the network descriptor from the platform-invite payload
    /// via PartyManager::DeserializeNetworkDescriptor() and pass the deserialized descriptor to
    /// PartyNetwork::ConnectToNetwork(). After connecting, the remote user joins by authenticating into the network via
    /// PartyNetwork::AuthenticateLocalUser() with the invitation identifier in the platform-invite payload.
    /// </para>
    /// </remarks>
    /// <param name="networkDescriptor">
    /// The output network descriptor.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyCreateNewNetworkCompletedStateChange" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyManager::SerializeNetworkDescriptor" />
    /// <seealso cref="PartyManager::DeserializeNetworkDescriptor" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    /// <seealso cref="PartyInvitation" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyNetwork::GetInvitations" />
    /// <seealso cref="PartyInvitation::GetInvitationConfiguration" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    PartyError GetNetworkDescriptor(
        _Out_ PartyNetworkDescriptor * networkDescriptor
        ) const party_no_throw;

    /// <summary>
    /// Gets the network configuration which was set when creating the network.
    /// </summary>
    /// <remarks>
    /// Returns a null pointer until a call to PartyManager::StartProcessingStateChanges() returns a
    /// PartyStateChangeType::NetworkConfigurationMadeAvailable state change.
    /// </remarks>
    PartyError GetNetworkConfiguration(
        _Outptr_ const PartyNetworkConfiguration ** networkConfiguration
        ) const party_no_throw;

    /// <summary>
    /// Kicks a device from the network.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// </remarks>
    PartyError KickDevice(
        const PartyDevice * targetDevice,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Kicks a user from the network along with all devices that user is on.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// </remarks>
    PartyError KickUser(
        PartyString targetEntityId,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the value of a shared property.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If there is no property associated with the key, the resulting value will be nullptr. The returned value is only
    /// valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedProperty(
        PartyString key,
        _Outptr_result_maybenull_ const PartyDataBuffer ** value
        ) const party_no_throw;

    /// <summary>
    /// Gets an array of all property keys.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// The returned array is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedPropertyKeys(
        _Out_ uint32_t * propertyCount,
        _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
        ) const party_no_throw;

    /// <summary>
    /// Sets or removes multiple shared properties associated with this object.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If a nullptr value is passed in the array, the corresponding key will be removed. Existing properties not
    /// specified in the call will remain unchanged.
    /// </para>
    /// </remarks>
    PartyError SetSharedProperties(
        uint32_t propertyCount,
        _In_reads_(propertyCount) const PartyString * keys,
        _In_reads_(propertyCount) const PartyDataBuffer * values
        ) party_no_throw;

    /// <summary>
    /// Connects the local chat control to the network.
    /// </summary>
    /// <remarks>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyNetwork::GetChatControls() or PartyChatControl::GetNetworks() for <paramref name="chatControl" />, as it
    /// synchronously updates those arrays. PartyManager::StartProcessingStateChanges() also invalidates the memory for
    /// those arrays.
    /// </remarks>
    PartyError ConnectChatControl(
        _In_ PartyLocalChatControl * chatControl,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Disconnects the local chat control from the network.
    /// </summary>
    PartyError DisconnectChatControl(
        _In_ PartyLocalChatControl * chatControl,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the chat controls connected to this network.
    /// </summary>
    /// <remarks>
    /// The returned array is valid until the next call to either PartyManager::StartProcessingStateChanges() or
    /// PartyNetwork::ConnectChatControl() on this network.
    /// </remarks>
    PartyError GetChatControls(
        _Out_ uint32_t * chatControlCount,
        _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
        ) const party_no_throw;

    /// <summary>
    /// Gets one or more statistic counter values for the network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// This function is used to retrieve performance counters, queue lengths, historical usage metrics, or other
    /// statistical information recorded for this network.
    /// </para>
    /// <para>
    /// A given PartyNetworkStatistic type may appear in any order in the <paramref name="statisticTypes" /> array, but
    /// must not be specified more than once. Each corresponding statistic value will be written to the <paramref
    /// name="statisticValues" /> array in the same order.
    /// </para>
    /// <para>
    /// The returned statistic values are always the most current ones available. There is no guarantee they will report
    /// the same value from one GetNetworkStatistics() call to the next, even if there were no intervening calls to
    /// PartyManager::StartProcessingStateChanges() or PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="statisticCount">
    /// The number of statistics in the input <paramref name="statisticTypes" /> array and to be written in the
    /// <paramref name="statisticValues" /> output array. This must be at least 1.
    /// </param>
    /// <param name="statisticTypes">
    /// The <paramref name="statisticCount" /> entry input array of unique PartyNetworkStatistic types to retrieve.
    /// </param>
    /// <param name="statisticValues">
    /// The <paramref name="statisticCount" /> entry output array where the statistic values should be written. Each
    /// statistic value will be written at the same entry index corresponding to where the requested
    /// PartyNetworkStatistic appears in the <paramref name="statisticTypes" /> input array.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the network statistics succeeded or an error code otherwise. The
    /// human-readable form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyNetworkStatistic" />
    /// <seealso cref="PartyLocalEndpoint::GetEndpointStatistics" />
    PartyError GetNetworkStatistics(
        uint32_t statisticCount,
        _In_reads_(statisticCount) const PartyNetworkStatistic * statisticTypes,
        _Out_writes_all_(statisticCount) uint64_t * statisticValues
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this network object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyNetwork::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this network object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the network without requiring a mapping lookup. The value is retrieved using the
    /// PartyNetwork::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the network object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyNetwork::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyNetwork() = delete;
    PartyNetwork(const PartyNetwork&) = delete;
    PartyNetwork(PartyNetwork&&) = delete;
    PartyNetwork& operator=(const PartyNetwork&) = delete;
    PartyNetwork& operator=(PartyNetwork&&) = delete;
    ~PartyNetwork() = delete;
};

/// <summary>
/// The management class for chat operations.
/// </summary>
class PartyChatControl
{
public:
    /// <summary>
    /// Gets the PartyLocalChatControl version of this chat control.
    /// </summary>
    /// <remarks>
    /// If this chat control is not a local chat control, nullptr is returned.
    /// </remarks>
    PartyError GetLocal(
        _Outptr_result_maybenull_ PartyLocalChatControl ** localChatControl
        ) const party_no_throw;

    /// <summary>
    /// Returns the device this chat control is associated with.
    /// </summary>
    PartyError GetDevice(
        _Outptr_ PartyDevice ** device
        ) const party_no_throw;

    /// <summary>
    /// Gets the PlayFab Entity ID of the user associated with this chat control.
    /// </summary>
    /// <remarks>
    /// The memory for the Entity ID string remains valid for the life of the chat control, which is until its
    /// ChatControlDestroyed and/or DestroyChatControlCompleted state change, depending on the type of destruction that
    /// occurred, has been provided via PartyManager::StartProcessingStateChanges() and all state changes referencing
    /// the chat control have been returned to PartyManager::FinishProcessingStateChanges().
    /// </remarks>
    /// <param name="entityId">
    /// The output Entity ID.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError GetEntityId(
        _Outptr_ PartyString * entityId
        ) const party_no_throw;

    /// <summary>
    /// Gets the value of a shared property.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If there is no property associated with the key, the resulting value will be nullptr. The returned value is only
    /// valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedProperty(
        PartyString key,
        _Outptr_result_maybenull_ const PartyDataBuffer ** value
        ) const party_no_throw;

    /// <summary>
    /// Gets an array of all property keys.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// The returned array is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetSharedPropertyKeys(
        _Out_ uint32_t * propertyCount,
        _Outptr_result_buffer_(*propertyCount) const PartyString ** keys
        ) const party_no_throw;

    /// <summary>
    /// Gets the networks to which this chat control is connected.
    /// </summary>
    /// <remarks>
    /// The returned array is only valid until the next call to either PartyManager::StartProcessingStateChanges() or
    /// PartyNetwork::ConnectChatControl().
    /// </remarks>
    PartyError GetNetworks(
        _Out_ uint32_t * networkCount,
        _Outptr_result_buffer_(*networkCount) PartyNetworkArray * networks
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this chat control
    /// object.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output Entity ID.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyChatControl::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this chat control object.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the chat control without requiring a mapping lookup. The value is retrieved using the
    /// PartyChatControl::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the chat control object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyChatControl::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyChatControl() = delete;
    PartyChatControl(const PartyChatControl&) = delete;
    PartyChatControl(PartyChatControl&&) = delete;
    PartyChatControl& operator=(const PartyChatControl&) = delete;
    PartyChatControl& operator=(PartyChatControl&&) = delete;
    ~PartyChatControl() = delete;
};

/// <summary>
/// The management class for chat operations related to the local device.
/// </summary>
class PartyLocalChatControl : public PartyChatControl
{
public:
    /// <summary>
    /// Gets the local user associated with this local chat control.
    /// </summary>
    /// <param name="localUser">
    /// The output PartyLocalUser.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError GetLocalUser(
        _Outptr_ PartyLocalUser ** localUser
        ) const party_no_throw;

    /// <summary>
    /// Sets the chat permissions between the local chat control and a target chat control.
    /// </summary>
    /// <remarks>
    /// The target chat control can be either remote or local. The default permission set is
    /// PartyChatPermissionOptions::None. This setting is local only; if I use this to send voice chat to a remote chat
    /// control, they must also have configured themselves to allow voice chat from this chat control.
    /// <para>
    /// There is no explicit permission for sending chat text; that should be considered when constructing the list of
    /// target chat controls when calling PartyLocalChatControl::SendText().
    /// </para>
    /// <para>
    /// The Party library does no enforcement of platform restrictions. Platform restrictions must be considered when
    /// setting the chat permissions between two chat controls.
    /// </para>
    /// </remarks>
    PartyError SetPermissions(
        const PartyChatControl * targetChatControl,
        PartyChatPermissionOptions chatPermissionOptions
        ) party_no_throw;

    /// <summary>
    /// Gets the voice communication relationship between the local chat control and a target chat control.
    /// </summary>
    PartyError GetPermissions(
        const PartyChatControl * targetChatControl,
        _Out_ PartyChatPermissionOptions * chatPermissionOptions
        ) const party_no_throw;

    /// <summary>
    /// Transmits a chat text string to each specified target chat control.
    /// </summary>
    /// <remarks>
    /// <para>
    /// Sending chat text to local chat controls is not currently supported. If the array of target chat controls
    /// includes any local targets, this call will synchronously fail.
    /// </para>
    /// <para>
    /// There is no guaranteed translation, localization, or offensive language filtering of the text content; the chat
    /// text string will be presented with the text as is.
    /// </para>
    /// <para>
    /// If a target chat control is not connected to at least one network in common with the source chat control, the
    /// text string will not be delivered. This is possible if there are two local chat controls. A target chat control
    /// connected to one of the local chat controls may not be connected to all other local chat controls.
    /// </para>
    /// <para>
    /// The PartyDataBuffer structures in the <paramref name="dataBuffers" /> array are for auxiliary data associated
    /// with the chat text, such as metadata indicating the color that should be used to render the text or a binary
    /// blob containing image data for an icon to render along with the chat text. For sending game data that is
    /// unrelated to text chat, see PartyLocalEndpoint::SendMessage(), a messaging option that exposes finer control
    /// over message transmission behavior.
    /// </para>
    /// <para>
    /// Callers provide 0 or more PartyDataBuffer structures in the <paramref name="dataBuffers" /> array. The memory
    /// that the structures reference does not have to be contiguous, making it easy to have a fixed header buffer
    /// followed by a variable payload, for example. The buffers will be assembled in order, transmitted, and delivered
    /// to the targeted chat controls as a single contiguous data block, separate from the chat text, in a
    /// PartyChatTextReceivedStateChange. The Party library does not expend bandwidth transmitting metadata to describe
    /// the original PartyDataBuffer segmentation.
    /// </para>
    /// </remarks>
    /// <param name="targetChatControlCount">
    /// The number of target chat controls in the <paramref name="targetChatControls" /> array.
    /// </param>
    /// <param name="targetChatControls">
    /// The <paramref name="targetChatControlCount" /> entry array of target PartyChatControls.
    /// </param>
    /// <param name="dataBufferCount">
    /// The number of buffer structures provided in the <paramref name="dataBuffers" /> array.
    /// </param>
    /// <param name="dataBuffers">
    /// The <paramref name="dataBufferCount" /> entry array of PartyDataBuffer structures describing an auxiliary
    /// message payload to send. This is ignored when <paramref name="dataBufferCount" /> is zero.
    /// </param>
    /// <seealso cref="PartyChatTextReceivedStateChange" />
    PartyError SendText(
        uint32_t targetChatControlCount,
        _In_reads_(targetChatControlCount) PartyChatControlArray targetChatControls,
        PartyString chatText,
        uint32_t dataBufferCount,
        _In_reads_(dataBufferCount) const PartyDataBuffer * dataBuffers
        ) party_no_throw;

    /// <summary>
    /// Configures the preferred microphone or recording device that the chat control will use for audio input.
    /// </summary>
    /// <remarks>
    /// If the specified device isn't present, the chat control will subscribe to audio device changes and use the
    /// device when it does appear.
    /// </remarks>
    /// <param name="audioDeviceSelectionType" />
    /// If PartyAudioDeviceSelectionType::None is specified, the audio input will be cleared. If
    /// PartyAudioDeviceSelectionType::SystemDefault is specified, the Party library will attempt to use the system's
    /// default communication device. If PartyAudioDeviceSelectionType::PlatformUserDefault is specified, the Party
    /// library will attempt to use the default communication device associated with
    /// <paramref name="audioDeviceSelectionContext" />. If PartyAudioDeviceSelectionType::Manual is specified, the
    /// Party library will attempt to use the communication device whose device identifier matches
    /// <paramref name="audioDeviceSelectionContext" />.
    /// </param>
    /// <param name="audioDeviceSelectionContext">
    /// When using PartyAudioDeviceSelectionType::None or PartyAudioDeviceSelectionType::SystemDefault,
    /// <paramref name="audioDeviceSelectionContext" /> will be ignored. When using
    /// PartyAudioDeviceSelectionType::PlatformUserDefault, <paramref name="audioDeviceSelectionContext" /> must be the
    /// non-null, non-empty platform-specific user context that the chat control should use when selecting the audio
    /// device. When using PartyAudioDeviceSelectionType::Manual, <paramref name="audioDeviceSelectionContext" /> must
    /// be the non-null, non-empty identifier of the audio device that the chat control should use.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyLocalChatControl::GetAudioInput" />
    /// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
    PartyError SetAudioInput(
        PartyAudioDeviceSelectionType audioDeviceSelectionType,
        _In_opt_ PartyString audioDeviceSelectionContext,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Provides the preferred microphone or recording device that the chat control has been configured to use for audio
    /// input.
    /// </summary>
    /// <remarks>
    /// An empty device identifier string indicates that no input has been selected.
    /// </remarks>
    /// <param name="audioDeviceSelectionType">
    /// An output value indicating the selection type that was used to select the provided <paramref name="deviceId" />.
    /// </param>
    /// <param name="audioDeviceSelectionContext">
    /// When using PartyAudioDeviceSelectionType::None, <paramref name="audioDeviceSelectionContext" /> will be empty.
    /// When using PartyAudioDeviceSelectionType::SystemDefault, <paramref name="audioDeviceSelectionContext" /> will be
    /// empty. When using PartyAudioDeviceSelectionType::PlatformUserDefault,
    /// <paramref name="audioDeviceSelectionContext" /> will be the value provided in a previous call to
    /// PartyLocalChatControl::SetAudioInput(). When using PartyAudioDeviceSelectionType::Manual,
    /// <paramref name="audioDeviceSelectionContext" /> will be empty.
    /// </param>
    /// <param name="deviceId">
    /// An output value indicating the selected audio input device's identifier.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::SetAudioInput" />
    /// <seealso cref="PartyLocalChatControl::GetAudioOutput" />
    PartyError GetAudioInput(
        _Out_ PartyAudioDeviceSelectionType * audioDeviceSelectionType,
        _Outptr_ PartyString * audioDeviceSelectionContext,
        _Outptr_ PartyString * deviceId
        ) const party_no_throw;

    /// <summary>
    /// Configures the preferred speakers or headset device that the chat control will use for audio output.
    /// </summary>
    /// <remarks>
    /// If the specified device isn't present, the chat control will subscribe to audio device changes and use the
    /// device when it does appear.
    /// </remarks>
    /// <param name="audioDeviceSelectionType" />
    /// If PartyAudioDeviceSelectionType::None is specified, the audio output will be cleared. If
    /// PartyAudioDeviceSelectionType::SystemDefault is specified, the Party library will attempt to use the system's
    /// default communication device. If PartyAudioDeviceSelectionType::PlatformUserDefault is specified, the Party
    /// library will attempt to use the default communication device associated with
    /// <paramref name="audioDeviceSelectionContext" />. If PartyAudioDeviceSelectionType::Manual is specified, the
    /// Party library will attempt to use the communication device whose device identifier matches
    /// <paramref name="audioDeviceSelectionContext" />.
    /// </param>
    /// <param name="audioDeviceSelectionContext">
    /// When using PartyAudioDeviceSelectionType::None or PartyAudioDeviceSelectionType::SystemDefault,
    /// <paramref name="audioDeviceSelectionContext" /> will be ignored. When using
    /// PartyAudioDeviceSelectionType::PlatformUserDefault, <paramref name="audioDeviceSelectionContext" /> must be the
    /// non-null, non-empty platform-specific user context that the chat control should use when selecting the audio
    /// device. When using PartyAudioDeviceSelectionType::Manual, <paramref name="audioDeviceSelectionContext" /> must
    /// be the non-null, non-empty identifier of the audio device that the chat control should use.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyLocalChatControl::GetAudioOutput" />
    /// <seealso cref="PartyLocalChatControl::SetAudioInput" />
    PartyError SetAudioOutput(
        PartyAudioDeviceSelectionType audioDeviceSelectionType,
        _In_opt_ PartyString audioDeviceSelectionContext,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Provides the preferred speakers or headset device that the chat control has been configured to use for audio
    /// output.
    /// </summary>
    /// <remarks>
    /// An empty device identifier string indicates that no output has been selected.
    /// </remarks>
    /// <param name="audioDeviceSelectionType">
    /// An output value indicating the selection type that was used to select the provided <paramref name="deviceId" />.
    /// </param>
    /// <param name="audioDeviceSelectionContext">
    /// When using PartyAudioDeviceSelectionType::None, <paramref name="audioDeviceSelectionContext" /> will be empty.
    /// When using PartyAudioDeviceSelectionType::SystemDefault, <paramref name="audioDeviceSelectionContext" /> will be
    /// empty. When using PartyAudioDeviceSelectionType::PlatformUserDefault,
    /// <paramref name="audioDeviceSelectionContext" /> will be the value provided in a previous call to
    /// PartyLocalChatControl::SetAudioOutput(). When using PartyAudioDeviceSelectionType::Manual,
    /// <paramref name="audioDeviceSelectionContext" /> will be empty.
    /// </param>
    /// <param name="deviceId">
    /// An output value indicating the selected audio output device's identifier.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::SetAudioOutput" />
    /// <seealso cref="PartyLocalChatControl::GetAudioInput" />
    PartyError GetAudioOutput(
        _Out_ PartyAudioDeviceSelectionType * audioDeviceSelectionType,
        _Outptr_ PartyString * audioDeviceSelectionContext,
        _Outptr_ PartyString * deviceId
        ) const party_no_throw;

    /// <summary>
    /// Populates the local chat control's list of supported text to speech profiles.
    /// </summary>
    /// <remarks>
    /// This is an asynchronous operation; a PartyPopulateAvailableTextToSpeechProfilesCompletedStateChange will be
    /// provided via PartyManager::StartProcessingStateChanges() on completion.
    /// <para>
    /// The asynchronous operation must complete successfully before GetAvailableTextToSpeechProfiles() can be called.
    /// </para>
    /// </remarks>
    /// <seealso cref="PartyLocalChatControl::GetAvailableTextToSpeechProfiles" />
    /// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
    /// <seealso cref="PartyLocalChatControl::GetTextToSpeechProfile" />
    /// <seealso cref="PartyStateChangeType::PopulateAvailableTextToSpeechProfilesCompleted" />
    PartyError PopulateAvailableTextToSpeechProfiles(
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the text to speech profiles for this chat control.
    /// </summary>
    /// <remarks>
    /// This method synchronously returns the result cached by the last successful
    /// LocalChatControl::PopulateAvailableTextToSpeechProfiles() operation.
    /// <para>
    /// The returned array is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    PartyError GetAvailableTextToSpeechProfiles(
        _Out_ uint32_t * profileCount,
        _Outptr_result_buffer_(*profileCount) PartyTextToSpeechProfileArray * profiles
        ) const party_no_throw;

    /// <summary>
    /// Configures the profile to use for a specified type of text-to-speech operation.
    /// </summary>
    /// <remarks>
    /// <para>
    /// The profile provided will be used for all subsequent calls to PartyLocalChatControl::SynthesizeTextToSpeech()
    /// that specify the same value for <paramref name="type" />. No profile will be configured until
    /// PartyLocalChatControl::SetTextToSpeechProfile() is called at least once. Thus, this method must be called at
    /// least once before any calls to PartyLocalChatControl::SynthesizeTextToSpeech() can succeed.
    /// </para>
    /// <para>
    /// This method accepts a profile identifier to indicate the profile selection so that titles may either pass in
    /// the result of PartyTextToSpeechProfile::GetIdentifier() or provide a profile identifer cached from a previous
    /// Party library session.
    /// </para>
    /// <para>
    /// Multiple PartyLocalChatControl::SetTextToSpeechProfile() operations can be initiated, and they will be
    /// asynchronously queued. Each operation will be processed and completed in order.
    /// </para>
    /// <para>
    /// This is an asynchronous operation; a PartySetTextToSpeechProfileCompletedStateChange will be provided via
    /// PartyManager::StartProcessingStateChanges() on completion.
    /// </para>
    /// </remarks>
    /// <param name="type">
    /// The type of text-to-speech operations for which the specified profile should be used.
    /// </param>
    /// <param name="profileIdentifier">
    /// The identifier of the profile that text-to-speech operations of the specified type should use.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::GetTextToSpeechProfile" />
    /// <seealso cref="PartyStateChangeType::SetTextToSpeechProfileCompletedStateChange" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    PartyError SetTextToSpeechProfile(
        PartySynthesizeTextToSpeechType type,
        PartyString profileIdentifier,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the profile that was last configured from a successfully completed
    /// PartyLocalChatControl::SetTextToSpeechProfile() operation for a specified type of text-to-speech operation.
    /// </summary>
    /// <remarks>
    /// If no profile has been successfully configured for the specified type of text-to-speech operation, the
    /// retrieved profile will be null.
    /// <para>
    /// The retrieved profile will update when a PartySetTextToSpeechProfileCompletedStateChange associated with a
    /// call to PartyLocalChatControl::SetTextToSpeechProfile(), which specified the same value for <paramref
    /// name="type" />, is provided via PartyManager::StartProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="type">
    /// The type of text-to-speech operations for which the profile should be retrieved.
    /// </param>
    /// <param name="profile">
    /// The output to which the profile pointer will be written. The profile may be null if none has been set for the
    /// specified type. The pointer is only valid until the next call to PartyManager::StartProcessingStateChanges().
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
    /// <seealso cref="PartyStateChangeType::SetTextToSpeechProfileCompletedStateChange" />
    PartyError GetTextToSpeechProfile(
        PartySynthesizeTextToSpeechType type,
        _Outptr_result_maybenull_ PartyTextToSpeechProfile ** profile
        ) const party_no_throw;

    /// <summary>
    /// Generates text-to-speech audio that is used to either displace the microphone audio associated with this chat
    /// control or render directly to the chat control's audio output.
    /// </summary>
    /// <remarks>
    /// <para>
    /// SynthesizeTextToSpeech() cannot be called for a particular <paramref name="type" /> until a text-to-speech
    /// profile has been configured for the specified <paramref name="type" /> via
    /// PartyLocalChatControl::SetTextToSpeechProfile().
    /// </para>
    /// <para>
    /// SynthesizeTextToSpeech() can be called immediately after configuring a text-to-speech profile via a call to
    /// SetTextToSpeechProfile() with the same <paramref name="type" />. In such a case, the text-to-speech operation
    /// will be queued behind the completion of the SetTextToSpeechProfile() operation.
    /// </para>
    /// </remarks>
    /// <param name="type">
    /// The type of text-to-speech operation.
    /// </param>
    /// <param name="textToSynthesize">
    /// The text from which to synthesize audio.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
    PartyError SynthesizeTextToSpeech(
        PartySynthesizeTextToSpeechType type,
        PartyString textToSynthesize,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Configures the language associated with this chat control.
    /// </summary>
    /// <remarks>
    /// If no language is specified, the user's default, as determined by the platform, will be used. The language is
    /// used as the spoken language associated with this chat control for transcription and the target language for
    /// incoming translations. If the language code specified is en-US, for instance, the input audio to this chat
    /// control will be treated as the English (United States) language and transcribed as such. If translation is
    /// enabled via either PartyLocalChatControl::SetVoiceChatTranscriptionOptions() or
    /// PartyLocalChatControl::SetTextChatOptions(), the incoming voice chat transcriptions and/or text chat will be
    /// translated to English (United States).
    /// <para>
    /// The language code should be in BCP 47 format; supported language codes are enumerated at
    /// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support. Specifying an
    /// unsupported or invalid language code will not cause this method to fail, but will result in failure to
    /// generate transcriptions associated with this chat control. The language code can be queried via
    /// LocalChatControl::GetLanguage().
    /// </para>
    /// </remarks>
    /// <param name="languageCode">
    /// The new BCP 47 language code the chat control should use with future communication. If this value is nullptr,
    /// the user's default, as determined by the platform, will be used.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyLocalChatControl::GetLanguage" />
    /// <seealso cref="PartyLocalChatControl::SetVoiceChatTranscriptionOptions" />
    /// <seealso cref="PartyLocalChatControl::SetTextChatTranscriptionOptions" />
    PartyError SetLanguage(
        _In_opt_ PartyString languageCode,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the language associated with this chat control.
    /// </summary>
    /// <remarks>
    /// The language is used as the spoken language associated with this chat control for transcription and the target
    /// language for incoming translations. If the language code specified is en-US, for instance, the input audio to
    /// this chat control will be treated as the English (United States) language and transcribed as such. If
    /// translation is enabled via either PartyLocalChatControl::SetVoiceChatTranscriptionOptions() or
    /// PartyLocalChatControl::SetTextChatOptions(), the incoming voice chat transcriptions and/or text chat will be
    /// translated to English (United States).
    /// <para>
    /// The language code should be in BCP 47 format; supported language codes are enumerated at
    /// https://docs.microsoft.com/en-us/azure/cognitive-services/speech-service/language-support. Specifying an
    /// unsupported or invalid language code will not cause this method to fail, but will result in failure to
    /// generate transcriptions associated with this chat control. The language code can be queried via
    /// LocalChatControl::GetLanguage().
    /// </para>
    /// </remarks>
    /// <param name="languageCode">
    /// The BCP 47 language code used by the chat control future communication. The string remains valid until the
    /// next PartySetLanguageCompletedStateChange is provided via PartyManager::StartProcessingStateChanges() or the
    /// chat control is destroyed.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartySetLanguageCompletedStateChange" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    /// <seealso cref="PartyLocalDevice::CreateChatControl" />
    /// <seealso cref="PartyLocalChatControl::SetLanguage" />
    /// <seealso cref="PartyLocalChatControl::SetVoiceChatTranscriptionOptions" />
    /// <seealso cref="PartyLocalChatControl::SetTextChatTranscriptionOptions" />
    PartyError GetLanguage(
        _Outptr_ PartyString * languageCode
        ) const party_no_throw;

    /// <summary>
    /// Configures the transcription options associated with voice chat audio for this chat control.
    /// </summary>
    /// <remarks>
    /// Transcription is the process of generating strings representing spoken phrases in voice chat. The options
    /// specified via <paramref name="options" /> specify the chat controls that should generate these transcription
    /// strings, which are subsequently provided to the local chat control via
    /// PartyStateChangeType::VoiceChatTranscriptionReceived state changes.
    /// <para>
    /// Only chat controls configured to use a language that supports transcription, via
    /// PartyLocalDevice::CreateChatControl() or PartyLocalChatControl::SetLanguage(), will provide transcriptions.
    /// </para>
    /// </remarks>
    /// <param name="options">
    /// Options associated with voice chat transcription, such as which chat controls should generate transcriptions
    /// for the local chat control, and whether those transcriptions should be translated to the local chat control's
    /// language.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    PartyError SetTranscriptionOptions(
        PartyVoiceChatTranscriptionOptions options,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Provides the transcription options associated with voice chat audio for this chat control.
    /// </summary>
    /// <remarks>
    /// Transcription is the process of generating strings representing spoken phrases in voice chat. The options
    /// specified via <paramref name="options" /> specify the chat controls that should generate these transcription
    /// strings, which are subsequently provided to the local chat control via
    /// PartyStateChangeType::VoiceChatTranscriptionReceived state changes.
    /// <para>
    /// Only chat controls configured to use a language that supports transcription, via
    /// PartyLocalDevice::CreateChatControl() or PartyLocalChatControl::SetLanguage(), will provide transcriptions.
    /// </para>
    /// </remarks>
    /// <param name="options">
    /// Options associated with voice chat transcription, such as whether it should be enabled only for the local chat
    /// control, remote chat controls, or none.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    PartyError GetTranscriptionOptions(
        _Out_ PartyVoiceChatTranscriptionOptions * options
        ) const party_no_throw;

    /// <summary>
    /// Configures the text chat options associated with text chat for this chat control.
    /// </summary>
    /// <param name="options">
    /// Options associated with text chat, such as whether incoming text chat should be translated.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state
    /// change with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    PartyError SetTextChatOptions(
        PartyTextChatOptions options,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Provides the text chat options associated with text chat for this chat control.
    /// </summary>
    /// <param name="options">
    /// Options associated with text chat.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error
    /// code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    PartyError GetTextChatOptions(
        _Out_ PartyTextChatOptions * options
        ) const party_no_throw;

    /// <summary>
    /// Configures the volume setting for audio received from a target chat control that will be used for the local chat
    /// control.
    /// </summary>
    /// <remarks>
    /// The volume is a fractional percentage between 0.0 (quietest possible) and 1.0 (the standard chat volume).
    /// <para>
    /// This is a local setting that takes effect immediately.
    /// </para>
    /// </remarks>
    PartyError SetAudioRenderVolume(
        const PartyChatControl * targetChatControl,
        float volume
        ) party_no_throw;

    /// <summary>
    /// Provides the volume setting for audio received from a target chat control that will be used for the local chat
    /// control.
    /// </summary>
    /// <remarks>
    /// The volume is a fractional percentage between 0.0 (quietest possible) and 1.0 (the standard chat volume).
    /// <para>
    /// This is a local setting that takes effect immediately.
    /// </para>
    /// </remarks>
    PartyError GetAudioRenderVolume(
        const PartyChatControl* targetChatControl,
        _Out_ float * volume
        ) const party_no_throw;

    /// <summary>
    /// Configures whether the user's audio input is in the mute state.
    /// </summary>
    /// <remarks>
    /// Muting determines whether audio data will be captured from the chat control's audio input and sent to the
    /// appropriate chat controls according to the configured relationships. When the audio input is muted, no audio
    /// data will be captured, regardless of the relationships that have been configured. Muting does not stop outgoing
    /// text messages or audio that has been generated by a call to SynthesizeTextToSpeech().
    /// </remarks>
    PartyError SetAudioInputMuted(
        PartyBool muted
        ) party_no_throw;

    /// <summary>
    /// Provides whether the user's audio input is in the mute state.
    /// </summary>
    /// <remarks>
    /// Muting determines whether audio data will be captured from the chat control's audio input and sent to the
    /// appropriate chat controls according to the configured relationships. When the audio input is muted, no audio
    /// data will be captured, regardless of the relationships that have been configured. Muting does not stop outgoing
    /// text messages or audio that has been generated by a call to SynthesizeTextToSpeech().
    /// </remarks>
    PartyError GetAudioInputMuted(
        _Out_ PartyBool * muted
        ) const party_no_throw;

    /// <summary>
    /// Provides whether the incoming audio from the target chat control has previously been muted in relation to the
    /// local chat control.
    /// </summary>
    /// <remarks>
    /// Audio muting determines whether incoming voice audio from the target chat control will be rendered to the local
    /// chat control.
    /// </remarks>
    PartyError SetIncomingAudioMuted(
        const PartyChatControl * targetChatContorl,
        PartyBool muted
        ) party_no_throw;

    /// <summary>
    /// Provides whether the incoming audio from the target chat control has previously been muted in relation to the
    /// local chat control.
    /// </summary>
    /// <remarks>
    /// Audio muting determines whether incoming voice audio from the target chat control will be rendered to the local
    /// chat control.
    /// </remarks>
    PartyError GetIncomingAudioMuted(
        const PartyChatControl * targetChatControl,
        _Out_ PartyBool * muted
        ) const party_no_throw;

    /// <summary>
    /// Provides whether the incoming text messages from the target chat control has previously been muted in relation
    /// to the local chat control.
    /// </summary>
    /// <remarks>
    /// Chat text muting determines whether incoming chat text messages from the target chat control will be provided to
    /// the local chat control.
    /// </remarks>
    PartyError SetIncomingTextMuted(
        const PartyChatControl * targetChatControl,
        PartyBool muted
        ) party_no_throw;

    /// <summary>
    /// Provides whether the incoming text messages from the target chat control has previously been muted in relation
    /// to the local chat control.
    /// </summary>
    /// <remarks>
    /// Chat text muting determines whether incoming chat text messages from the target chat control will be provided to
    /// the local chat control.
    /// </remarks>
    PartyError GetIncomingTextMuted(
        const PartyChatControl * targetChatControl,
        _Out_ PartyBool * muted
        ) const party_no_throw;

    /// <summary>
    /// Provides a chat indicator specifying the audio state of the local chat control.
    /// </summary>
    /// <remarks>
    /// This indicator is intended to assist UI iconic representation so that users can determine whether their voice
    /// audio is being captured and, if not, then why not.
    /// <para>
    /// This value changes frequently and is typically polled every graphics frame.
    /// </para>
    /// </remarks>
    PartyError GetLocalChatIndicator(
        _Out_ PartyLocalChatControlChatIndicator * chatIndicator
        ) const party_no_throw;

    /// <summary>
    /// Provides a chat indicator specifying the audio state of a target chat control in relation to the local chat
    /// control.
    /// </summary>
    /// <remarks>
    /// This indicator is intended to assist UI iconic representation so that users can determine why they're hearing/
    /// seeing what they are ("who's that talking?"), or why not.
    /// <para>
    /// This value changes frequently and is typically polled every graphics frame.
    /// </para>
    /// </remarks>
    PartyError GetChatIndicator(
        const PartyChatControl * targetChatControl,
        _Out_ PartyChatControlChatIndicator * chatIndicator
        ) const party_no_throw;

    /// <summary>
    /// Configures the bitrate used to encode audio generated by this chat control.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// </remarks>
    PartyError SetAudioEncoderBitrate(
        uint32_t bitrate,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Provides the bitrate used to encode audio generated by this chat control.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// </remarks>
    PartyError GetAudioEncoderBitrate(
        _Out_ uint32_t * bitrate
        ) const party_no_throw;

    /// <summary>
    /// Sets or removes multiple shared properties associated with this object.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// If a nullptr value is passed in the array, the corresponding key will be removed. Existing properties not
    /// specified in the call will remain unchanged.
    /// </para>
    /// </remarks>
    PartyError SetSharedProperties(
        uint32_t propertyCount,
        _In_reads_(propertyCount) const PartyString * keys,
        _In_reads_(propertyCount) const PartyDataBuffer * values
        ) party_no_throw;

private:
    PartyLocalChatControl() = delete;
    PartyLocalChatControl(const PartyLocalChatControl&) = delete;
    PartyLocalChatControl(PartyLocalChatControl&&) = delete;
    PartyLocalChatControl& operator=(const PartyLocalChatControl&) = delete;
    PartyLocalChatControl& operator=(PartyLocalChatControl&&) = delete;
    ~PartyLocalChatControl() = delete;
};

/// <summary>
/// Represents the voice profile used to synthesize speech.
/// </summary>
/// <seealso cref="PartyLocalChatControl::PopulateAvailableTextToSpeechProfiles" />
/// <seealso cref="PartyLocalChatControl::GetAvailableTextToSpeechProfiles" />
/// <seealso cref="PartyLocalChatControl::SetTextToSpeechProfile" />
/// <seealso cref="PartyLocalChatControl::GetTextToSpeechProfile" />
class PartyTextToSpeechProfile
{
public:
    /// <summary>
    /// Gets the unique identifier associated with this profile.
    /// </summary>
    /// <seealso cref="LocalChatControl::SetTextToSpeechProfile" />
    PartyError GetIdentifier(
        _Outptr_ PartyString * identifier
        ) const party_no_throw;

    /// <summary>
    /// Gets the human-readable name of this profile.
    /// </summary>
    /// <remarks>
    /// This name is intended for use in title UI and logs, but is not localized.
    /// </remarks>
    PartyError GetName(
        _Outptr_ PartyString * name
        ) const party_no_throw;

    /// <summary>
    /// Gets the language code associated with this profile.
    /// </summary>
    PartyError GetLanguageCode(
        _Outptr_ PartyString * languageCode
        ) const party_no_throw;

    /// <summary>
    /// Gets the gender associated with this profile.
    /// </summary>
    PartyError GetGender(
        _Out_ PartyGender * gender
        ) const party_no_throw;

    /// <summary>
    /// Retrieves the app's private, custom pointer-sized context value previously associated with this profile.
    /// </summary>
    /// <remarks>
    /// If no custom context has been set yet, the value pointed to by <paramref name="customContext" /> is set to
    /// nullptr.
    /// </remarks>
    /// <param name="customContext">
    /// The output to which the custom context is written.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if retrieving the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyTextToSpeechProfile::SetCustomContext" />
    PartyError GetCustomContext(
        _Outptr_result_maybenull_ void ** customContext
        ) const party_no_throw;

    /// <summary>
    /// Configures an optional, custom pointer-sized context value with this profile.
    /// </summary>
    /// <remarks>
    /// The custom context is typically used as a "shortcut" that simplifies accessing local, title-specific memory
    /// associated with the profile without requiring a mapping lookup. The value is retrieved using the
    /// PartyTextToSpeechProfile::GetCustomContext() method.
    /// <para>
    /// Any configured value is treated as opaque by the library, and is only valid on the local device; it is not
    /// transmitted over the network.
    /// </para>
    /// </remarks>
    /// <param name="customContext">
    /// An arbitrary, pointer-sized value to store with the player object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if configuring the custom context succeeded or an error code otherwise. The human-readable
    /// form of the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyTextToSpeechProfile::GetCustomContext" />
    PartyError SetCustomContext(
        _In_opt_ void * customContext
        ) party_no_throw;

private:
    PartyTextToSpeechProfile() = delete;
    PartyTextToSpeechProfile(const PartyTextToSpeechProfile&) = delete;
    PartyTextToSpeechProfile(PartyTextToSpeechProfile&&) = delete;
    PartyTextToSpeechProfile& operator=(const PartyTextToSpeechProfile&) = delete;
    PartyTextToSpeechProfile& operator=(PartyTextToSpeechProfile&&) = delete;
    ~PartyTextToSpeechProfile() = delete;
};

/// <summary>
/// The primary management class for interacting with the Party library.
/// </summary>
/// <remarks>
/// Only a single instance of the class is permitted.
/// </remarks>
class PartyManager
{
public:
    /// <summary>
    /// Retrieves a reference to the PartyManager singleton instance.
    /// </summary>
    /// <returns>
    /// The PartyManager singleton instance.
    /// </returns>
    static PartyManager& GetSingleton(
        ) party_no_throw;

    /// <summary>
    /// Get the human-readable form of an error.
    /// </summary>
    /// <remarks>
    /// These error messages are not localized and are only intended for developers, i.e. these error messages are not
    /// intended to be shown to users via UI.
    /// </remarks>
    /// <param name="error">
    /// An error code.
    /// </param>
    /// <param name="errorMessage">
    /// The output, human-readable error message.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    static PartyError GetErrorMessage(
        PartyError error,
        _Outptr_ PartyString * errorMessage
        ) party_no_throw;

    /// <summary>
    /// Serializes a network descriptor structure into an opaque string that is safe to communicate over title and
    /// platform-specific communication channels.
    /// </summary>
    /// <remarks>
    /// A network descriptor contains all the information required for a device to connect to the network to which the
    /// descriptor is associated. <paramref name="serializedNetworkDescriptorString" /> is the serialized form of the
    /// descriptor specified by <paramref name="networkDescriptor" /> and is safe to communicate over title and
    /// platform-specific communication channels. The string may be up to <see
    /// cref="c_maxSerializedNetworkDescriptorStringLength" /> characters long, not including the null terminator, and
    /// will never contain non-ASCII, control, or other characters that would require JSON or XML escaping.
    /// <para>
    /// This method will fail if the network descriptor is not serializable. For example, the descriptor provided
    /// synchronously by a call to PartyManager::CreateNewNetwork() is not serializable because it does not contain
    /// enough information for a remote client to connect to the new network. The network descriptor changes and becomes
    /// serializable when the PartyCreateNewNetworkCompletedStateChange is provided and indicates success. The updated
    /// network descriptor is provided as a field in the PartyCreateNewNetworkCompletedStateChange. Once connected to
    /// the network, the descriptor can be retrieved using PartyNetwork::GetNetworkDescriptor().
    /// </para>
    /// <para>
    /// PartyNetworkDescriptors work in tandem with PartyInvitations to facilitate inviting remote users to join the
    /// network. First, obtain the network descriptor via PartyNetwork::GetNetworkDescriptor() and serialize it via
    /// PartyManager::SerializeNetworkDescriptor(). Next, create an invitation via PartyNetwork::CreateInvitation() or
    /// query for a preexisting invitation via PartyNetwork::GetInvitations() and obtain the invitation's identifier
    /// from its configuration via PartyInvitation::GetInvitationConfiguration(). Last, include both the serialized
    /// network descriptor and the invitation identifier in the payload of the platform-specific invite mechanism. When
    /// the remote user receives the invite, they deserialize the network descriptor from the platform-invite payload
    /// via PartyManager::DeserializeNetworkDescriptor() and pass the deserialized descriptor to
    /// PartyNetwork::ConnectToNetwork(). After connecting, the remote user joins by authenticating into the network via
    /// PartyNetwork::AuthenticateLocalUser() with the invitation identifier in the platform-invite payload.
    /// </para>
    /// <para>
    /// This method can be called prior to the PartyManager::Initialize() method.
    /// </para>
    /// </remarks>
    /// <param name="networkDescriptor">
    /// The network descriptor to serialize.
    /// </param>
    /// <param name="serializedNetworkDescriptorString">
    /// The output buffer to which the serialized network descriptor string is written. The serialized network
    /// descriptor string will never contain non-ASCII, control, or other characters that would require JSON or XML
    /// escaping.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the descriptor is serializable and was successfully serialized, or an error code
    /// otherwise.
    /// </returns>
    /// <seealso cref="PartyManager:DeserializeNetworkDescriptor" />
    /// <seealso cref="PartyNetwork::GetNetworkDescriptor" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    /// <seealso cref="PartyInvitation" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyNetwork::GetInvitations" />
    /// <seealso cref="PartyInvitation::GetInvitationConfiguration" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    static PartyError SerializeNetworkDescriptor(
        const PartyNetworkDescriptor * networkDescriptor,
        _Out_writes_z_(c_maxSerializedNetworkDescriptorStringLength + 1) char * serializedNetworkDescriptorString
        );

    /// <summary>
    /// Deserializes a network descriptor structure from an opaque string serialized via a prior call to
    /// PartyManager::SerializeNetworkDescriptor().
    /// </summary>
    /// <remarks>
    /// The resulting <paramref name="networkDescriptor" /> can be used to connect to a network via
    /// PartyManager::ConnectToNetwork().
    /// <para>
    /// This method can be called prior to the PartyManager::Initialize() method.
    /// </para>
    /// </remarks>
    /// <param name="serializedNetworkDescriptorString">
    /// The serialized network descriptor string.
    /// </param>
    /// <param name="networkDescriptor">
    /// The output network descriptor structure that will be populated after deserializing
    /// <paramref name="serializedNetworkDescriptorString" />.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the descriptor string is a valid serialized network descriptor string and was
    /// successfully deserialized, or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyManager::SerializeNetworkDescriptor" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    static PartyError DeserializeNetworkDescriptor(
        PartyString serializedNetworkDescriptorString,
        _Out_ PartyNetworkDescriptor * networkDescriptor
        );

    /// <summary>
    /// Optionally configures the memory allocation and freeing callbacks the Party library should use.
    /// </summary>
    /// <remarks>
    /// This method allows the title to install custom memory allocation routines in order to service all requests by
    /// the Party library for new memory buffers instead of using its default allocation routines.
    /// <para>
    /// The <paramref name="allocateMemoryCallback" /> and <paramref name="freeMemoryCallback" /> parameters can be null
    /// pointers to restore the default routines. Both callback pointers must be null or both must be non-null. Mixing
    /// custom and default routines is not permitted.
    /// </para>
    /// <para>
    /// This method must be called prior to the PartyManager::Initialize() method. The callbacks cannot change while any
    /// allocations are outstanding. It also must be only called by one thread at a time as it isn't multithreading
    /// safe.
    /// </para>
    /// <para>
    /// The configured callbacks are persisted until changed, including across calls to PartyManager::Cleanup().
    /// </para>
    /// </remarks>
    /// <param name="allocateMemoryCallback">
    /// A pointer to the custom allocation callback to use, or a null pointer to restore the default.
    /// </param>
    /// <param name="freeMemoryCallback">
    /// A pointer to the custom freeing callback to use, or a null pointer to restore the default.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyAllocateMemoryCallback" />
    /// <seealso cref="PartyFreeMemoryCallback" />
    /// <seealso cref="PartyManager::GetMemoryCallbacks" />
    static PartyError SetMemoryCallbacks(
        _In_opt_ PartyAllocateMemoryCallback allocateMemoryCallback,
        _In_opt_ PartyFreeMemoryCallback freeMemoryCallback
        ) party_no_throw;

    /// <summary>
    /// Retrieves the memory allocation and freeing callbacks the Party library is using.
    /// </summary>
    /// <remarks>
    /// This retrieves the memory allocation routines servicing requests by the Party library for new memory.
    /// <para>
    /// This method does not require the PartyManager::Initialize() method to have been called first.
    /// </para>
    /// </remarks>
    /// <param name="allocateMemoryCallback">
    /// A place to store a pointer to the memory allocation callback currently used.
    /// </param>
    /// <param name="freeMemoryCallback">
    /// A place to store a pointer to the memory freeing callback currently used.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyAllocateMemoryCallback" />
    /// <seealso cref="PartyFreeMemoryCallback" />
    /// <seealso cref="PartyManager::SetMemoryCallbacks" />
    static PartyError GetMemoryCallbacks(
        _Out_ PartyAllocateMemoryCallback * allocateMemoryCallback,
        _Out_ PartyFreeMemoryCallback * freeMemoryCallback
        ) party_no_throw;

    /// <summary>
    /// Optionally configures the processor on which internal Party library threads will run.
    /// </summary>
    /// <remarks>
    /// This method enables the title to configure the processor affinity for internal Party library threads of a given
    /// type.
    /// <para>
    /// This method may be called at any time before or after PartyManager::Initialize() and will take effect
    /// immediately. Thread processor settings are persisted across calls to PartyManager::Cleanup() and
    /// PartyManager::Initialize(). When there are more than 64 cores present, this method always applies to processor
    /// group 0.
    /// </para>
    /// <para>
    /// In order to specify any processor, pass <see cref="c_anyProcessor" /> as the <paramref name="threadAffinityMask"
    /// /> parameter. This is also the default value the Party library will use if this method is never called.
    /// </para>
    /// </remarks>
    /// <param name="threadId">
    /// The type of internal Party library thread to configure processor affinity.
    /// </param>
    /// <param name="threadAffinityMask">
    /// The affinity mask for this type of Party library thread.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyThreadId" />
    /// <seealso cref="PartyManager::GetThreadAffinityMask" />
    static PartyError SetThreadAffinityMask(
        PartyThreadId threadId,
        uint64_t threadAffinityMask
        ) party_no_throw;

    /// <summary>
    /// Retrieves the current set of processors on which internal Party library threads will run or are running as an
    /// affinity mask.
    /// </summary>
    /// <remarks>
    /// This retrieves the current processor affinity for internal Party library threads of a given type.
    /// <para>
    /// This method does not require PartyManager::Initialize() to have been called first.
    /// </para>
    /// <para>
    /// A reported value of <see cref="c_anyProcessor" /> written to <paramref name="threadAffinityMask" /> indicates
    /// that the thread is free to run on any processor.
    /// </para>
    /// </remarks>
    /// <param name="threadId">
    /// The type of internal Party library thread for which processor affinity should be retrieved.
    /// </param>
    /// <param name="threadAffinityMask">
    /// A place to store the affinity mask for this type of Party library thread.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyThreadId" />
    /// <seealso cref="PartyManager::SetThreadAffinityMask" />
    static PartyError GetThreadAffinityMask(
        PartyThreadId threadId,
        _Out_ uint64_t * threadAffinityMask
        ) party_no_throw;

    /// <summary>
    /// Initializes the PartyManager object instance.
    /// </summary>
    /// <remarks>
    /// This must be called before any other method, aside from the static methods PartyManager::GetSingleton(),
    /// PartyManager::SetMemoryCallbacks(), PartyManager::GetMemoryCallbacks(), PartyManager::SetThreadAffinityMask(),
    /// PartyManager::GetThreadAffinityMask(), PartyManager::SerializeNetworkDescriptor(), and
    /// PartyManager::DeserializeNetworkDescriptor(). PartyManager::Initialize() cannot be called again without a
    /// subsequent PartyManager::Cleanup() call.
    /// <para>
    /// Every call to PartyManager::Initialize() should have a corresponding PartyManager::Cleanup() call.
    /// </para>
    /// <para>
    /// The provided <paramref name="titleId" /> must be the same Title ID used to acquire the PlayFab Entity IDs and
    /// Entity Tokens that will be passed to PartyManager::CreateLocalUser().
    /// </para>
    /// </remarks>
    /// <param name="titleId">
    /// The title's PlayFab Title ID.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::CreateLocalUser" />
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::Cleanup" />
    /// <seealso cref="PartyManager::GetSingleton" />
    /// <seealso cref="PartyManager::SetMemoryCallbacks" />
    /// <seealso cref="PartyManager::GetMemoryCallbacks" />
    /// <seealso cref="PartyManager::SetThreadAffinityMask" />
    /// <seealso cref="PartyManager::GetThreadAffinityMask" />
    /// <seealso cref="PartyManager::SerializeNetworkDescriptor" />
    /// <seealso cref="PartyManager::DeserializeNetworkDescriptor" />
    PartyError Initialize(
        PartyString titleId
        ) party_no_throw;

    /// <summary>
    /// Immediately reclaims all resources associated with the PartyManager object.
    /// </summary>
    /// <remarks>
    /// If local users were participating in a PartyNetwork, they are removed ungracefully (it appears to remote devices
    /// as if network connectivity to this device has been lost), so best practice is to call
    /// PartyNetwork::LeaveNetwork() first on all networks returned from a call to PartyManager::GetNetworks() and wait
    /// for the corresponding PartyLeaveNetworkCompletedStateChange to have the local users exit any existing
    /// PartyNetworks gracefully.
    /// <para>
    /// Every call to PartyManager::Initialize() should have a corresponding PartyManager::Cleanup() call.
    /// </para>
    /// </remarks>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::Initialize" />
    /// <seealso cref="PartyNetwork::LeaveNetwork" />
    /// <seealso cref="PartyManager::GetNetworks" />
    PartyError Cleanup(
        ) party_no_throw;

    /// <summary>
    /// Retrieves an array of all PartyStateChanges to process since the last such call.
    /// </summary>
    /// <remarks>
    /// This method provides the Party library an opportunity to synchronize state with remote devices or services, and
    /// retrieves a list of all changes currently available for the title since the last call to this method. The title
    /// should use the provided array of 0 or more changes to update its own state or UI, and then call
    /// PartyManager::FinishProcessingStateChanges() with them in a timely manner.
    /// <para>
    /// Party library state exposed by the library can change during this call, so you must be thread-safe in your use
    /// of it. For example, invoking PartyManager::StartProcessingStateChanges() on your UI thread at the same time a
    /// separate worker thread is looping through the list of endpoints returned by PartyNetwork::GetEndpoints() may
    /// result in crashes because PartyManager::StartProcessingStateChanges() can alter the memory associated with the
    /// endpoint list. PartyManager::StartProcessingStateChanges() should be called frequently-- at least once per
    /// graphics frame. It's designed to execute and return quickly such that it can be called on your main UI thread
    /// with negligible impact. For best results, you should also minimize the time you spend handling state changes
    /// before calling PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="stateChangeCount">
    /// The output number of PartyStateChange entries for the title to handle in the <paramref name="stateChanges" />
    /// array.
    /// </param>
    /// <param name="stateChanges">
    /// The output array of all PartyStateChange entries for the title to handle and then pass to
    /// PartyManager::FinishProcessingStateChanges().
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyStateChange" />
    /// <seealso cref="PartyManager::FinishProcessingStateChanges" />
    PartyError StartProcessingStateChanges(
        _Out_ uint32_t * stateChangeCount,
        _Outptr_result_buffer_(*stateChangeCount) PartyStateChangeArray * stateChanges
        ) party_no_throw;

    /// <summary>
    /// Returns an array of PartyStateChanges that were being processed.
    /// </summary>
    /// <remarks>
    /// This method informs the Party library that the state changes reported by a previous call to
    /// PartyManager::StartProcessingStateChanges() have now been handled by the title, so their associated resources
    /// can be reclaimed. You may call PartyManager::FinishProcessingStateChanges() with any number of state changes.
    /// Each state change returned by PartyManager::StartProcessingStateChanges() must be included in a call to
    /// PartyManager::FinishProcessingStateChanges() exactly once but they may be returned out of order and may be
    /// interleaved with state changes from subsequent calls to PartyManager::StartProcessingStateChanges(). Even if
    /// state changes are held across subsequent calls to PartyManager::StartProcessingStateChanges, the Party library
    /// state returned by all getters will advance and may no longer reflect the same state that the held state changes
    /// refer to.
    /// <para>
    /// For best results, you should minimize the time you spend handling state changes before calling
    /// PartyManager::FinishProcessingStateChanges().
    /// </para>
    /// </remarks>
    /// <param name="stateChangeCount">
    /// The number of changes, provided in the list specified by <paramref name="stateChanges" />, previously returned
    /// by PartyManager::StartProcessingStateChanges() that have now been handled by the title.
    /// </param>
    /// <param name="stateChanges">
    /// The array of changes previously returned by PartyManager::StartProcessingStateChanges() that have now been
    /// handled by the title.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyStateChange" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    PartyError FinishProcessingStateChanges(
        uint32_t stateChangeCount,
        _In_reads_(stateChangeCount) PartyStateChangeArray stateChanges
        ) party_no_throw;

    /// <summary>
    /// Gets an array containing the set of regions for which your title is configured, along with roundtrip latency
    /// information.
    /// </summary>
    /// <remarks>
    /// The array provided by this method is not populated until the first PartyRegionsChangedStateChange is provided.
    /// Each subsequent PartyRegionsChangedStateChange indicates an update to this set of regions. Background operations
    /// to populate this set begin when PartyManager::Initialize() is called and, if this set hasn't yet been
    /// successfully populated, when PartyManager::CreateNewNetwork() is called.
    /// <para>
    /// The array will be sorted in order of increasing latency. Latency for a region is defined as the end-to-end time
    /// it takes to send a UDP datagram to the PlayFab Quality of Service beacon for that region and receive a response.
    /// The library will measure latency for each region several times in order to calculate high fidelity results.
    /// </para>
    /// <para>
    /// A latency equivalent to UINT32_MAX indicates that the region is supported but latency information could not be
    /// determined, either due to failures internal to the library or a ping timeout was reached without receiving a
    /// response from the beacon. This can be used for diagnostic purposes (a UINT32_MAX latency to every region likely
    /// indicates a local configuration problem) or used to filter out regions that are unlikely to be viable during
    /// region selection.
    /// </para>
    /// <para>
    /// For efficiency, the library measures latency on several threads that are affinitized to the processor specified
    /// for the networking threads via PartyManager::SetThreadAffinityMask(). The amortized worst-case time to complete
    /// latency measurements for each region is approximately 500 ms. The average time to complete latency measurements
    /// for each region will vary by network environment but will typically be much lower.
    /// </para>
    /// </remarks>
    /// <param name="regionCount">
    /// An output value indicating the number of regions provided in <paramref name="regions" />.
    /// </param>
    /// <param name="regions">
    /// An output array, backed by the library's internal memory, containing the set of regions.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyRegionsChangedStateChange" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    PartyError GetRegions(
        _Out_ uint32_t * regionCount,
        _Outptr_result_buffer_(*regionCount) const PartyRegion ** regions
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to create a new network.
    /// </summary>
    /// <remarks>
    /// <para>
    /// A PartyNetwork is a set of devices, such as Xbox One consoles and PCs, that are connected via a client-server
    /// topology to a transparent cloud relay server. Each device in the network contains a collection of endpoints
    /// associated with the network; directed messages can be sent from an endpoint on the local device to any set of
    /// endpoints, or broadcast to all endpoints. This function queues an attempt to allocate a relay, thus creating a
    /// new network, on behalf of the user represented by <paramref name="localUser" /> but does not connect the local
    /// device to the network.
    /// </para>
    /// <para>
    /// If no devices connect to the network within ten minutes of the relay's creation, it will shutdown. The network
    /// will stay active indefinitely while at least one device is connected, migrating to a new relay if required. If
    /// no devices are connected to the network, the relay will become inactive and shutdown after one minute of
    /// inactivity.
    /// </para>
    /// <para>
    /// The local device can queue an attempt to connect to the new network by immediately passing <paramref
    /// name="networkDescriptor" /> to PartyManager::ConnectToNetwork(). Using this descriptor with
    /// SerializeNetworkDescriptor() will result in failure because the descriptor does not contain enough information
    /// for a remote device to connect to the network. The network descriptor changes and becomes serializable when the
    /// PartyCreateNewNetworkCompletedStateChange is provided and indicates success. The updated network descriptor is
    /// provided as a field in the PartyCreateNewNetworkCompletedStateChange. Once connected to the network, the
    /// descriptor can be retrieved using PartyNetwork::GetNetworkDescriptor().
    /// </para>
    /// <para>
    /// The network is created in the first available region using the order specified in <paramref name="regions" />.
    /// If none of the specified regions are available, the network will not be created. Specifying 0 for <paramref
    /// name="regionCount" /> defaults to using all regions in which the title is configured, ordered by lowest latency.
    /// </para>
    /// <para>
    /// The initial invitation for the newly created network will not be owned by any user. Therefore calling
    /// PartyInvitation::GetEntityId() will return a null string for the initial invitation. As well, the initial
    /// invitation for the newly created network will persist for the lifetime of the network until specifically revoked
    /// via PartyNetwork::RevokeInvitation(). New invitations can be created for the network via
    /// PartyNetwork::CreateInvitation() by local users that are authenticated into the network, and those invitations
    /// will persist until their creating local users are removed from the network. Users join the network via
    /// PartyNetwork::AuthenticateLocalUser() by providing the identifier of an invitation that was successfully
    /// created, has not been revoked, and allows them to join.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user to which the network creation and relay allocation is attributed.
    /// </param>
    /// <param name="networkConfiguration">
    /// Network configuration properties such as max user count and max device count. These properties last for the
    /// lifetime of the network and cannot be changed.
    /// </param>
    /// <param name="regionCount">
    /// The number of regions provided in the array of preferred regions specified via <paramref name="regions" />. If
    /// this is zero, the library will use all regions in which the title is configured, ordered by lowest latency.
    /// </param>
    /// <param name="regions">
    /// The array of preferred regions in which the network should be created. The network will be created in the first
    /// available region.
    /// </param>
    /// <param name="initialInvitationConfiguration">
    /// An optionally specified configuration for the initial invitation.
    /// <para>
    /// If this value is null, then default configuration values will be used. By default, PlayFab Party will generate a
    /// unique invitation identifier for the title, the revocability will be PartyInvitationRevocability::Anyone, and
    /// the PlayFab Entity ID list will be empty, allowing any user to join using the invitation.
    /// </para>
    /// <para>
    /// If a configuration is provided, the title may optionally specify the identifier on the configuration. If the
    /// identifier is null or an empty string, the PlayFab Party library will generate an identifier for the title. It
    /// is guaranteed that this generated identifer will be different from all identifiers that the PlayFab Party
    /// library will generate for all future invitations on this network across all devices. Titles may specify their
    /// own identifier by providing a non-null, non-empty value in the configuration. If the title specifies the
    /// identifier, it is the title's responsibility to ensure that this identifier does not collide with the
    /// identifiers of future invitations created on this network via PartyNetwork::CreateInvitation() on any device.
    /// </para>
    /// <para>
    /// If a configuration is provided, its revocability must be PartyInvitationRevocability::Anyone.
    /// </para>
    /// <para>
    /// If a configuration is provided and the list of PlayFab Entity IDs is empty, all users will be allowed to join
    /// using the new invitation.
    /// </para>
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <param name="networkDescriptor">
    /// An optional, output network descriptor that can be used to immediately queue a connection of the local device to
    /// the newly created network via PartyManager::ConnectToNetwork().
    /// </param>
    /// <param name="appliedInitialInvitationIdentifier">
    /// An optional, output buffer to which the initial invitation's identifier is written. If
    /// <paramref name="initialInvitationConfiguration" /> has been provided with a non-null, non-empty identifier, then
    /// this buffer will be filled with the same identifier. If an initial configuration was not provided or the
    /// provided configuration had an empty or null identifier, the PlayFab Party library will generate one and return
    /// it to the title in this buffer.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the asynchronous operation to create a new network began, or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyCreateNewNetworkCompletedStateChange" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::LeaveNetwork" />
    /// <seealso cref="PartyNetwork::RevokeInvitation" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyInvitation" />
    /// <seealso cref="PartyInvitationConfiguration" />
    PartyError CreateNewNetwork(
        const PartyLocalUser * localUser,
        const PartyNetworkConfiguration * networkConfiguration,
        uint32_t regionCount,
        const PartyRegion * regions,
        _In_opt_ const PartyInvitationConfiguration * initialInvitationConfiguration,
        _In_opt_ void * asyncIdentifier,
        _Out_opt_ PartyNetworkDescriptor * networkDescriptor,
        _Out_writes_opt_z_(c_maxInvitationIdentifierStringLength + 1) char * appliedInitialInvitationIdentifier
        ) party_no_throw;

    /// <summary>
    /// Queues an asynchronous attempt to connect to a network.
    /// </summary>
    /// <remarks>
    /// This function queues an asynchronous attempt to connect to the network associated with <paramref
    /// name="networkDescriptor" /> by negotiating and establishing a secure DTLS connection from the local device to
    /// the transparent cloud relay server. A PartyConnectToNetworkCompletedStateChange will be provided upon completion
    /// of the asynchronous operation, indicating success or failure. On success, the local device will have established
    /// a connection to the transparent cloud relay server. On failure, a PartyNetworkDestroyedStateChange will be
    /// generated. No other devices will become visible, and the local device will not be visible to any remote devices,
    /// until at least one local user is successfully authenticated via PartyNetwork::AuthenticateLocalUser().
    /// <para>
    /// After the device successfully connects to the network, it must authenticate into the network via
    /// PartyNetwork::AuthenticateLocalUser(). If the device is connected to the network but unauthenticated for more
    /// than one minute, the device will be disconnected and a PartyNetworkDestroyedStateChange will be generated. This
    /// will occur regardless of whether the device never authenticated or lost authentication after calling
    /// PartyNetwork::RemoveLocalUser().
    /// </para>
    /// <para>
    /// This function optionally provides <paramref name="network" /> as output that can immediately be used to perform
    /// asynchronous network operations, such as PartyNetwork::CreateInvitation() and
    /// PartyNetwork::CreateEndpoint(). These asynchronous operations will be internally queued until the connection
    /// completes, at which point they will be processed. This <paramref name="network" /> will also be provided on the
    /// resulting PartyConnectToNetworkCompletedStateChange where it will be fully-connected and associated with the
    /// provided <paramref name="asyncIdentifier" />.
    /// </para>
    /// <para>
    /// This operation will asynchronously fail with PartyConnectToNetworkCompletedStateChange::result set to
    /// PartyStateChangeResult::NetworkLimitReached if the limit of connected devices for the network has been reached
    /// as specified in the network's configuration when it was created via PartyManager::CreateNewNetwork().
    /// </para>
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyManager::GetNetworks(), as it synchronously adds the new network to the array.
    /// PartyManager::StartProcessingStateChanges() also invalidates the memory for the array.
    /// </para>
    /// </remarks>
    /// <param name="networkDescriptor">
    /// The descriptor associated with the network to which a connection will be established.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <param name="network">
    /// An optional, output network object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the asynchronous operation to connect to a new network began, or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyConnectToNetworkCompletedStateChange" />
    /// <seealso cref="PartyNetworkConfiguration" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyManager::GetNetworks" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::RemoveLocalUser" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyNetwork::RevokeInvitation" />
    /// <seealso cref="PartyNetwork::CreateEndpoint" />
    /// <seealso cref="PartyNetwork::LeaveNetwork" />
    PartyError ConnectToNetwork(
        const PartyNetworkDescriptor * networkDescriptor,
        _In_opt_ void * asyncIdentifier,
        _Outptr_opt_ PartyNetwork ** network
        ) party_no_throw;

    /// <summary>
    /// Queues an attempt to synchronize the sends to specified endpoints, and optionally all shared properties.
    /// </summary>
    /// <remarks>
    /// This function is currently unimplemented and will always fail.
    /// <para>
    /// This function is about synchronizing how the endpoints listed receive data. This function guarantees that listed
    /// endpoints will receive all data sent to them over their respective networks from the local device before
    /// receiving any data sent after this function was called.
    /// </para>
    /// </remarks>
    /// <param name="endpointCount">
    /// The count of endpoints, specified by <paramref name="endpoints" />, to which data sends should be synchronized.
    /// </param>
    /// <param name="endpoints">
    /// The list of endpoints to which data sends should be synchronized.
    /// </param>
    /// <param name="options">
    /// Additional message synchronization options.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    PartyError SynchronizeMessagesBetweenEndpoints(
        uint32_t endpointCount,
        _In_reads_(endpointCount) PartyEndpointArray endpoints,
        PartySynchronizeMessagesBetweenEndpointsOptions options,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets the local device.
    /// </summary>
    /// <remarks>
    /// The local device represents the physical device on which the title is executing, such as an Xbox One or PC. Once
    /// the library is initialized, this method will always succeed in returning a local device. The local device will
    /// also appear in the device list of any network to which the local device has connected via
    /// PartyManager::ConnectToNetwork().
    /// </remarks>
    /// <param name="localDevice">
    /// The output local device.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    PartyError GetLocalDevice(
        _Outptr_ PartyLocalDevice ** localDevice
        ) const party_no_throw;

    /// <summary>
    /// Creates a local user object that is used to represent a local user when performing networking and chat
    /// operations.
    /// </summary>
    /// <remarks>
    /// This object takes a PlayFab Entity ID as <paramref name="entityId" /> and a PlayFab Entity Token as <paramref
    /// name="titlePlayerEntityToken" />. No synchronous validation is performed upon these values except that the
    /// length of <paramref name="entityId" /> is less than or equal to <see cref="c_maxEntityIdStringLength" />. When
    /// the library performs operations that require user authentication or authorization, such as creating a network,
    /// authenticating into a network, or performing speech-to-text transcription, the Party service will validate that
    /// the token is valid, is associated with the Entity ID provided, and is authorized to perform the operation. If
    /// these conditions aren't met, the operation will fail.
    /// <para>
    /// A PlayFab Entity ID and Entity Token can be obtained through the output of a PlayFab login operation and then
    /// provided as input to this function. The PlayFab Entity ID must be of type `title_player_account` which, for most
    /// developers, represents the "player" in the most traditional way.
    /// </para>
    /// <para>
    /// The provided <paramref name="entityId" /> and <paramref name="titlePlayerEntityToken" /> must have been acquired
    /// using the same Title ID that was passed to PartyManager::Initialize().
    /// </para>
    /// <para>
    /// The PlayFab Entity Token must be valid at the time PartyManager::CreateLocalUser() is called. The Party library
    /// copies this token and uses the copy for operations that require authentication or authorization of the local
    /// user, such as PartyManager::CreateNewNetwork() or PartyNetwork::AuthenticateLocalUser(). The Party library will
    /// refresh its copy of the token on a background networking thread as required. If the token provided to this call
    /// is invalid, operations that require a valid token would never succeed.
    /// </para>
    /// <para>
    /// Only c_maxLocalUsersPerDeviceCount PartyLocalUser objects may exist simultaneously at any given time. This
    /// method will synchronously fail if creating another local user would exceed that limit.
    /// </para>
    /// <para>
    /// On successful return, this method invalidates the memory for any array previously returned by
    /// PartyManager::GetLocalUsers(), as it synchronously adds the new user to the array.
    /// PartyManager::StartProcessingStateChanges() also invalidates the memory for the array.
    /// </para>
    /// </remarks>
    /// <param name="entityId">
    /// The PlayFab Entity ID to associate with the local user.
    /// </param>
    /// <param name="titlePlayerEntityToken">
    /// The PlayFab Entity Token to associate with the local user.
    /// </param>
    /// <param name="localUser">
    /// The output local user object.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if creating the local user succeeded or an error code otherwise. The human-readable form of
    /// the error code can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::Initialize" />
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::GetLocalUsers" />
    /// <seealso cref="PartyManager::DestroyLocalUser" />
    /// <seealso cref="PartyManager::CreateNewNetwork" />
    /// <seealso cref="PartyManager::CreateChatControl" />
    /// <seealso cref="PartyNetwork::AuthenticateLocalUser" />
    /// <seealso cref="PartyNetwork::RemoveLocalUser" />
    /// <seealso cref="PartyNetwork::CreateInvitation" />
    /// <seealso cref="PartyNetwork::RevokeInvitation" />
    /// <seealso cref="PartyNetwork::CreateEndpoint" />
    PartyError CreateLocalUser(
        PartyString entityId,
        PartyString titlePlayerEntityToken,
        _Outptr_ PartyLocalUser ** localUser
        ) party_no_throw;

    /// <summary>
    /// Starts an asynchronous operation to destroy a local user.
    /// </summary>
    /// <remarks>
    /// A successful return value signifies that the asynchronous operation has started and a DestroyLocalUserCompleted
    /// state change is guaranteed to eventually be provided, via PartyManager::StartProcessingStateChanges(), with the
    /// result of the operation. A failing return value signifies that the asynchronous operation will not execute and
    /// no completion state change will be provided. If the asynchronous operation succeeds, the local user will be
    /// removed from the list returned by PartyManager::GetLocalUsers() during the
    /// PartyManager::StartProcessingStateChanges() call that provides the DestroyLocalUserCompleted state change. The
    /// user object will be destroyed upon returning the final state change referencing the user via
    /// PartyManager::FinishProcessingStateChanges().
    /// <para>
    /// Before the asynchronous operation completes, i.e. before the DestroyLocalUserCompleted state change is provided
    /// by PartyManager::StartProcessingStateChanges(), the local user will be removed from all objects and networks
    /// referencing the local user. If the object depended on the user to remain in a valid state, such as with a chat
    /// control or endpoint tied to the user, or a network where the local user is the only authenticated local user,
    /// the object will be destroyed and the relevant state change will be provided prior to the
    /// DestroyLocalUserCompleted state change.
    /// </para>
    /// </remarks>
    /// <param name="localUser">
    /// The local user to destroy.
    /// </param>
    /// <param name="asyncIdentifier">
    /// An optional, app-defined, pointer-sized context value that can be used to associate the completion state change
    /// with this call.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the operation to destroy the local user started or an error code otherwise.
    /// </returns>
    /// <seealso cref="PartyDestroyLocalUserCompletedStateChange" />
    /// <seealso cref="PartyManager::GetLocalUsers" />
    PartyError DestroyLocalUser(
        const PartyLocalUser * localUser,
        _In_opt_ void * asyncIdentifier
        ) party_no_throw;

    /// <summary>
    /// Gets an array containing all local users created by CreateLocalUser().
    /// </summary>
    /// <remarks>
    /// The array is backed by the library's internal memory. The array is only valid until the next call to either
    /// PartyManager::CreateLocalUser() or PartyManager::StartProcessingStateChanges(). The individual local user
    /// objects are valid until the local user's PartyDestroyLocalUserCompletedStateChange is reported and all state
    /// changes referencing the local user object are returned via PartyManager::FinishProcessingStateChanges().
    /// </remarks>
    /// <param name="userCount">
    /// An output value indicating the number of local users provided in <paramref name="localUsers" />.
    /// </param>
    /// <param name="localUsers">
    /// An output array, backed by the library's internal memory, containing the local users.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::CreateLocalUser" />
    /// <seealso cref="PartyManager::DestroyLocalUser" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    /// <seealso cref="PartyManager::FinishProcessingStateChanges" />
    PartyError GetLocalUsers(
        _Out_ uint32_t * userCount,
        _Outptr_result_buffer_(*userCount) PartyLocalUserArray * localUsers
        ) const party_no_throw;

    /// <summary>
    /// Gets an array of all networks to which the local device is connected.
    /// </summary>
    /// <remarks>
    /// The array is backed by the library's internal memory. The array is only valid until the next call to
    /// PartyManager::StartProcessingStateChanges(). The individual network objects are valid until the network is
    /// destroyed and all state changes referencing the network have been returned via
    /// PartyManager::FinishProcessingStateChanges().
    /// </remarks>
    /// <param name="networkCount">
    /// An output value indicating the number of networks to which the local device is connected provided in <paramref
    /// name="networks" />.
    /// </param>
    /// <param name="networks">
    /// An output array, backed by the library's internal memory, containing the networks to which the local device is
    /// connected.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::ConnectToNetwork" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    PartyError GetNetworks(
        _Out_ uint32_t * networkCount,
        _Outptr_result_buffer_(*networkCount) PartyNetworkArray * networks
        ) const party_no_throw;

    /// <summary>
    /// Gets an array that contains a combined list of all chat controls on the local device and all remote devices.
    /// </summary>
    /// <remarks>
    /// The array is backed by the library's internal memory. The array is only valid until the next call to either
    /// PartyManager::CreateChatControl() or PartyManager::StartProcessingStateChanges(). The individual chat control
    /// objects are valid until the chat control is destroyed and all state changes referencing the chat control object
    /// are returned via PartyManager::FinishProcessingStateChanges().
    /// </remarks>
    /// <param name="chatControlCount">
    /// An output value indicating the number of networks to which the local device is connected provided in <paramref
    /// name="chatControls" />.
    /// </param>
    /// <param name="chatControls">
    /// An output array, backed by the library's internal memory, containing the list of all chat controls.
    /// </param>
    /// <returns>
    /// c_partyErrorSuccess if the call succeeded or an error code otherwise. The human-readable form of the error code
    /// can be retrieved via PartyManager::GetErrorMessage().
    /// </returns>
    /// <seealso cref="PartyManager::GetErrorMessage" />
    /// <seealso cref="PartyManager::CreateChatControl" />
    /// <seealso cref="PartyManager::StartProcessingStateChanges" />
    /// <seealso cref="PartyManager::FinishProcessingStateChanges" />
    PartyError GetChatControls(
        _Out_ uint32_t * chatControlCount,
        _Outptr_result_buffer_(*chatControlCount) PartyChatControlArray * chatControls
        ) const party_no_throw;

private:
    PartyManager();
    ~PartyManager();
    PartyManager(const PartyManager&) = delete;
    PartyManager(PartyManager&&) = delete;
    PartyManager& operator=(const PartyManager&) = delete;
    PartyManager& operator=(PartyManager&&) = delete;
    void * _handle;
};
}; // Party

#pragma pop_macro("DEFINE_ENUM_FLAG_OPERATORS")
