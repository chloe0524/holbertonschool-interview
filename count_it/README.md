# Count It!

Recursive Reddit API keyword counter for hot article titles.

## Description

Queries the Reddit API recursively to count keyword occurrences in hot article titles from a specified subreddit. Results are sorted by count (descending), then alphabetically (ascending).

## Requirements

- Python 3.x
- requests library

## Installation

```bash
pip install requests
```

## Usage

```bash
python3 0-main.py <subreddit> '<space-separated keywords>'
```

## Examples

```bash
python3 0-main.py programming 'python java javascript'
```

Output:
```
java: 27
javascript: 20
python: 17
```

```bash
python3 0-main.py programming 'JavA java'
```

Output:
```
java: 54
```

## Features

- Recursive API calls with pagination
- Case-insensitive matching
- Duplicate keywords are summed
- Word boundary detection (`java` ≠ `javascript`)
- Sorted by count (desc), then alphabetically (asc)
- Invalid subreddits print nothing
- No redirect following

## Function

```python
def count_words(subreddit, word_list, after=None, word_count=None)
```

## Files

- `0-count.py` - Main implementation
- `0-main.py` - Test file

## Author

Holberton School Interview Project
