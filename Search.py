def read_words_from_file(file_path):
    with open(file_path, 'r') as file:
        # Read the file and split it into words, ignoring punctuation and converting to lowercase
        words = set(word.strip().lower() for word in file.read().split())
    return words

def compare_word_files(file1, file2):
    words_file1 = read_words_from_file(file1)
    words_file2 = read_words_from_file(file2)

    # Find the matching words
    matching_words = words_file1.intersection(words_file2)
    return matching_words

def main():
    file1 = '/Users/ethanpham/Desktop/RandomWords.txt'  # Replace with your first file name
    file2 = '/Users/ethanpham/Desktop/SearchWords.txt'  # Replace with your second file name

    matching_words = compare_word_files(file1, file2)
    print(f"Number of matching words: {len(matching_words)}")
    print("Matching words:", matching_words)

if __name__ == "__main__":
    main()
