# CADVentory AI Tagging System

## Overview
This project aims to automate the tagging of `.g` files in CADVentory by leveraging an offline large language model (LLM). The process involves extracting relevant metadata from `.g` files, feeding this data into an LLM, and storing the generated tags in an SQLite database for efficient retrieval.

## Implementation Plan
### 1. Extracting Metadata from `.g` Files
To obtain key information such as the model title and object files, we will utilize the `mged` command-line tool. Example usage:

```sh
git mged -c teapot.g title
```

This command will return the title of the `teapot.g` model. Similar commands will be used to extract other relevant metadata.

### 2. Processing & Feeding Data into an Offline LLM
Once metadata is extracted, it will be formatted into a structured prompt and passed to an offline LLM for generating relevant tags. Some potential LLM options include:
- **GPT4All**
- **Llama.cpp**
- **Mistral AI**

### 3. Storing Tags in SQLite Database
The generated tags will be stored in an SQLite database for easy querying. The database schema will include:

```sql
CREATE TABLE IF NOT EXISTS ModelTags (
    ID INTEGER PRIMARY KEY,
    Title TEXT,
    Tags TEXT
);
```

Each `.g` file entry will include its title and a set of generated tags.

## Steps for Implementation
1. **Set up a C++ project** to handle metadata extraction, LLM processing, and database integration.
2. **Execute `mged` commands in C++** using `popen()` to retrieve model metadata.
3. **Pass extracted metadata to an LLM**, format it into a structured prompt, and receive tag suggestions.
4. **Store the generated tags in SQLite** using the `sqlite3` library in C++.
5. **Ensure efficient retrieval** of tagged `.g` files by implementing optimized database queries.

## Future Enhancements
- Implement **AI-driven predictive search** for more accurate file retrieval.
- Optimize LLM prompts to improve tag accuracy.
- Introduce **user feedback mechanisms** for refining tag suggestions.
- Implement security measures to ensure safe handling of `.g` files.

## Conclusion
This project will significantly improve `.g` file retrieval within CADVentory by automating the tagging process through AI. By using an offline LLM and integrating an SQLite database, we ensure both efficiency and security while enabling a seamless user experience.

---

For contributions and discussions, please refer to the repository's issues and pull requests.

