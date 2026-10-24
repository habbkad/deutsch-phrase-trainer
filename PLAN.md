# German Phrase Trainer — Product and Build Plan

**Status:** Proposal for approval  
**Platform:** Expo / React Native, iOS and Android  
**Audience:** English-speaking German learners at CEFR A2–B2

## Product goal

Help learners turn useful German phrases into language they can understand and say in real situations. Lessons should be short, level-aware, organized around everyday contexts, and give learners repeated chances to listen, recall, and use each phrase.

## Research notes (24 October 2026)

- **Busuu** positions its courses across CEFR A1–B2, providing a useful precedent for an explicit level path. Its course model suggests organizing content into levels, chapters, and lessons rather than an unstructured phrase dictionary. [Busuu course structure](https://www.busuu.com/de/it-works/courses)
- **Babbel Guided Conversations** use scripted real-life scenarios, let learners listen before speaking, and give a low-pressure route into dialogue. Babbel currently documents German guided conversations at A1/A2, leaving room for a focused A2–B2 app that carries scenario practice further into intermediate and upper-intermediate language. [Babbel Guided Conversations](https://support.babbel.com/hc/en-gb/articles/19188554247186-Guided-Conversations)
- **German Tokyo** combines phrase/sentence context, English meanings, recorded German audio, flashcards, fill-in-the-blank, word order, and dictation. This supports pairing each phrase with examples and multiple recall formats. [German Tokyo](https://german.tokyo/en/)
- **Deutsch im Griff** emphasizes CEFR level selection, spaced repetition, reading/listening, and offline access. Those are useful expectations for this audience, though offline content can be a later milestone. [Deutsch im Griff](https://deutschimgriff.com/?lang=en)
- **Expo Speech** provides on-device text-to-speech on Android, iOS, and web. It accepts a BCP 47 language tag, voice identifier, rate and pitch, and can list available voices at runtime. We should request `de-DE`, choose a compatible available voice when possible, and retain a safe system-default fallback. The docs note that iOS silent mode can suppress speech. [Expo Speech documentation](https://docs.expo.dev/versions/latest/sdk/speech/)

## Product requirements

### MVP

1. **Level and topic browsing:** A2, B1 and B2; practical topics such as introductions, appointments, work, housing, travel, health, shopping, opinions and problem-solving.
2. **Phrase cards:** German phrase, natural English translation, level, topic, short usage/context note, and one example or dialogue turn. Indicate register (formal/informal) where relevant.
3. **German text-to-speech:** Listen button on phrase and example; `de-DE` locale; normal and slower playback; stop current utterance before starting another; sensible fallback if a German voice is unavailable.
4. **Practice loop:** Listen and understand → reveal translation → recall/choose or complete the phrase → mark again / difficult / learned. Start with lightweight local spaced review.
5. **Progress:** Daily review count, studied phrases, and level/topic completion; avoid streak pressure as a core learning mechanic.
6. **Search and favorites:** Find phrases by German, English or topic; save useful phrases for review.
7. **Persistence:** Store onboarding level, saved phrases, review state and progress locally on device for MVP.

### Later, after validation

- Scripted two-person dialogues and shadowing mode.
- Recording and speech recognition with pronunciation feedback (separate evaluation; TTS alone does not assess learner speech).
- More advanced adaptive scheduling, downloadable/offline audio or content, account sync, reminders, and optional curated phrase packs.
- Additional interface languages and placement assessment.

## Learning/content model

Each phrase record should include: `id`, `level` (A2/B1/B2), `topic`, `de`, `en`, `context`, optional `register`, optional `exampleDe`/`exampleEn`, and tags. Begin with a small, carefully reviewed seed set (roughly 10–15 phrases per level across a few core topics) so quality and app flow can be checked before expanding. Phrase wording should be natural German and level labels should describe complexity/use, not claim formal exam alignment.

## Proposed app structure

- **Home:** Continue learning, due reviews, level/topic shortcuts.
- **Explore:** Filter by CEFR level and topic; searchable phrase list.
- **Learn session:** One phrase at a time with play, reveal, and recall actions.
- **Phrase detail:** Translation, context/register, example and audio.
- **Review:** Due phrases with again / difficult / learned actions.
- **Progress:** Learning totals and coverage by level/topic.
- **Settings:** Starting level, speech speed, and voice availability/help.

## Technical approach

- Expo React Native with TypeScript and Expo Router if compatible with the repository’s current setup.
- `expo-speech` for device-native speech synthesis. Enumerate voices once, prefer a German voice (`de-DE`, with appropriate German-language fallback), pass its identifier to speech calls, and use `language: 'de-DE'` even when falling back. Handle rapid taps by calling `Speech.stop()` before the next phrase.
- Local phrase content as typed JSON/TS data; local persistence for preferences, favorites and review progress. Keep content and scheduling logic separable so a backend or sync can be added later.
- Accessibility: clear type hierarchy, large audio/review touch targets, screen-reader labels and sufficient contrast.

## Execution plan (approval gates)

1. **Project scaffold and visual direction:** Establish Expo app shell, navigation, theme, and shared components; confirm app starts on iOS/Android targets.
2. **Content foundation:** Define validated phrase schema and add initial A2–B2 phrase sample with translations, context and register notes.
3. **Core learning flow:** Build onboarding/level selection, home, explore/search, phrase detail, favorites, and guided learning session.
4. **German speech:** Integrate `expo-speech`, locale and voice detection, speed control, stop/replay, and unavailable-voice handling.
5. **Review and progress:** Add local review scheduling, recall actions, persistence, and progress views.
6. **Polish and verification:** Check small and large screens, navigation, empty states, offline behavior for local content, accessibility, and speech on available simulators/devices.

## Acceptance criteria for the first usable release

- Learner can select A2, B1 or B2, browse topics, search phrases and save favorites.
- Every German phrase/example can be spoken aloud with a German system voice when available, including a slower option.
- Learner can complete a short practice session and see due-review state survive app restart.
- A2/B1/B2 labels and topic filters are visible; phrase context and formal/informal usage are clear.
- Core phrase content is locally available and core browsing/practice does not require network access.

## Decisions to confirm before implementation

1. **Interface language:** assume English UI with German learning content.
2. **Initial scope:** assume a personal, local-first MVP; no account, backend, AI tutor, microphone assessment, subscription, or social features in the first release.
3. **Project location/name:** created as `deutsch-phrase-trainer` in the current workspace; rename or relocate if preferred.

## Main risks and mitigations

- **System voices differ by device:** detect available voices and document device settings/fallback; later consider recorded native audio if consistent quality is essential.
- **Phrase quality matters:** seed small, review carefully, include context and register, expand in batches.
- **TTS is not pronunciation scoring:** keep speaking assessment out of MVP and treat it as a later feature requiring speech recognition and evaluation.
- **A2–B2 is broad:** make level and topic selection explicit and let learners choose their starting point.
