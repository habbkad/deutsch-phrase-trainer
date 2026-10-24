# Catalog sources and attribution

The expanded word catalog is derived from the A1–B2 `goethe-5000` rows in the public `hasharmujahid/deutsch-karten` dataset, using its English glosses, example sentences, level tags and source IDs. Its repository describes the code as MIT and documents its dataset sources and terms in `LICENCE-DATA.md`.

- Dataset repository: https://github.com/hasharmujahid/deutsch-karten
- Data licence and attribution notes: https://github.com/hasharmujahid/deutsch-karten/blob/main/LICENCE-DATA.md
- Underlying Goethe-Institut word lists: © Goethe-Institut; the upstream notes say to preserve attribution and respect Goethe-Institut terms.
- Wiktionary enrichment: CC BY-SA 4.0. We do not redistribute the source rows' audio, IPA, plural forms, or Wiktionary material in this app catalog.
- OpenSubtitles 2018 corpus frequencies: CC BY-SA 4.0.

The app keeps each entry in the exact CEFR band supplied by its source tag; lower-level entries are not copied into higher-level catalogs. The current imported word counts are A2: 584, B1: 1,815, and B2: 1,929, plus the six curated phrase cards in each level. Counts reflect unique source entries after removing repeated copies that previously appeared in cumulative catalogs. The source dataset has a smaller exact-tagged A2 subset, so the exact-level A2 catalog is below 1,000 entries.

Source dataset version inspected: `content_version` 3. See the linked repository for full third-party attribution and upstream license details.
