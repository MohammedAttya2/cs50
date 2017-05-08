import nltk
from tokenize import tokenize

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        self.positives = []
        self.negatives = []
        file_positives = open(positives, 'r')
        file_negatives = open(negatives, 'r')

        for line in file_positives:
            if not line.startswith(';') or not line.startswith(' '):
                self.positives.append(line.strip())

        for line in file_negatives:
            if not line.startswith(';') or not line.startswith(' '):
                self.negatives.append(line.strip())



    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)

        score = 0

        for word in tokens:
            if word.lower() in self.positives:
                score += 1
            elif word.lower() in self.negatives:
                score -= 1
        return score
