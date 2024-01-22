
#pragma once

#include "CoreMinimal.h"
#include "AkGameObject.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyAudioSubsystem.generated.h"


UCLASS(Blueprintable, Abstract)
class MYUEPROJECT_API UMyAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	/**
	 * Post a Wwise event on the Music and UI 2D object
	 * @param AudioEvent 
	 * @return 
	 */
	UFUNCTION(BlueprintCallable)
	void PostAudioEvent2D(UAkAudioEvent* AudioEvent);

	/**
	 * Plays a new music event and stops the previous one if its Short ID is different
	 * Ensures that there is always one and only one music instance playing.
	 * @param MusicEvent New Music Ak Audio Event
	 * @param PreviousEventFadeOutMs Fade Out time of the previous music track
	 * @param FadeCurve Fade Out curve of the previous music track
	 * @return Success?
	 */
	UFUNCTION(BlueprintCallable)
	bool PlayNewMusicEvent(UAkAudioEvent* MusicEvent, int32 PreviousEventFadeOutMs, EAkCurveInterpolation FadeCurve);

	/**
	 * Stops the current music event
	 * @param FadeOutMs Fade Out time
	 * @param FadeCurve Fade Out curve
	 * @return Success?
	 */
	UFUNCTION(BlueprintCallable)
	bool StopCurrentMusicEvent(int32 FadeOutMs, EAkCurveInterpolation FadeCurve);
	
private:

	// Music and UI object and 2D Listener
	
	const AkGameObjectID NON_WORLD_LISTENER_OBJECT = 1;
	const AkGameObjectID MUSIC_AND_UI_OBJECT = 2;

	// Current Music Instance and Short ID to fade out or stop the music sequence
	
	AkPlayingID CurrentMusicInstanceID = 0;
	AkUInt32 CurrentMusicEventShortID = 0;

	// Registers new AkGameObjects on the Sound Engine
	void RegisterAkGameObjects() const;

	/**
	 * This function is called after the Game Instance, and before any world is created.
	 * It is an ideal place to register any persistent AK Object before the world is ready.
	 */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};
