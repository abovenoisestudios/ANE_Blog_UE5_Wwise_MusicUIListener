
#include "MyAudioSubsystem.h"

#include "AkAudioEvent.h"
#include "Wwise/API/WwiseSoundEngineAPI.h"


void UMyAudioSubsystem::PostAudioEvent2D(UAkAudioEvent* AudioEvent)
{
	if (!IsValid(AudioEvent)) // If the audio event is not valid, return
	{
		return;
	}
	
	// Post the audio event on the MUSIC_AND_UI_OBJECT
	AudioEvent->PostOnGameObjectID(MUSIC_AND_UI_OBJECT,{}, {},
		nullptr, static_cast<AkCallbackType>(0),  {});
}

bool UMyAudioSubsystem::PlayNewMusicEvent(UAkAudioEvent* MusicEvent, int32 PreviousEventFadeOutMs, EAkCurveInterpolation FadeCurve)
{
	IWwiseSoundEngineAPI* WwiseSoundEngine = IWwiseSoundEngineAPI::Get(); // Gets a pointer to the Wwise Sound Engine 
	if (!IsValid(MusicEvent) || !WwiseSoundEngine) // If the audio event or the sound engine is not valid, return
	{
		return false;
	}

    // If the provided music event is the same as the one currently playing, return
	if (CurrentMusicEventShortID == MusicEvent->GetShortID())
	{
		return false;
	}

	if (CurrentMusicInstanceID > 0) // If there is a music instance playing, stop it using the fade-out parameters
	{
		WwiseSoundEngine->ExecuteActionOnPlayingID(AK::SoundEngine::AkActionOnEventType_Stop, CurrentMusicInstanceID,
			PreviousEventFadeOutMs, static_cast<AkCurveInterpolation>(FadeCurve));
	}

	// Post the music event on the MUSIC_AND_UI_OBJECT
	CurrentMusicInstanceID = MusicEvent->PostOnGameObjectID(MUSIC_AND_UI_OBJECT,{}, {},
		nullptr, static_cast<AkCallbackType>(0),  {});

	// Store the new music event short ID
	CurrentMusicEventShortID = MusicEvent->GetShortID();

	// If the AkPlayingID is 0 => fail
	// If the AkPlayingID is not 0 => success
	return CurrentMusicInstanceID > 0; 
}

bool UMyAudioSubsystem::StopCurrentMusicEvent(int32 FadeOutMs, EAkCurveInterpolation FadeCurve)
{
	IWwiseSoundEngineAPI* WwiseSoundEngine = IWwiseSoundEngineAPI::Get(); // Gets a pointer to the Wwise Sound Engine 
	if (CurrentMusicInstanceID == 0 || !WwiseSoundEngine) // If there is no music instance or the sound engine is not valid, return
	{
		return false;
	}

	// Stop the music instance
	WwiseSoundEngine->ExecuteActionOnPlayingID(AK::SoundEngine::AkActionOnEventType_Stop, CurrentMusicInstanceID,
			FadeOutMs, static_cast<AkCurveInterpolation>(FadeCurve));

	// Clear the current music instance ID and the Short ID
	CurrentMusicInstanceID = 0;
	CurrentMusicEventShortID = 0;
	
	return true;
}

void UMyAudioSubsystem::RegisterAkGameObjects() const
{
	IWwiseSoundEngineAPI* WwiseSoundEngine = IWwiseSoundEngineAPI::Get(); // Gets a pointer to the Wwise Sound Engine

	// Registers these Ak Game Objects on the Sound Engine and gives it a debug name
	WwiseSoundEngine->RegisterGameObj(NON_WORLD_LISTENER_OBJECT, "Listener (Non - World)");
	WwiseSoundEngine->RegisterGameObj(MUSIC_AND_UI_OBJECT, "Music and UI Object");

	// Assigns the listener of an object 
	WwiseSoundEngine->SetListeners(NON_WORLD_LISTENER_OBJECT, &NON_WORLD_LISTENER_OBJECT, 1);
	WwiseSoundEngine->SetListeners(MUSIC_AND_UI_OBJECT, &NON_WORLD_LISTENER_OBJECT, 1);
	
	// Create an audio channel configuration and set it to STEREO
	AkChannelConfig ChannelConfig;
	ChannelConfig.SetStandard(AK_SPEAKER_SETUP_STEREO);

	// Disable 3D spatialization on these objects
	WwiseSoundEngine->SetListenerSpatialization(NON_WORLD_LISTENER_OBJECT, false, ChannelConfig);
	WwiseSoundEngine->SetListenerSpatialization(MUSIC_AND_UI_OBJECT, false, ChannelConfig);
}

void UMyAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	RegisterAkGameObjects();
}
