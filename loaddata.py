from datasets import load_dataset
import json

# Load a small sample of the dataset
# You might want to specify 'streaming=True' for larger samples
# or use 'split="train[0:100000]"' to get a specific range
dataset = load_dataset("codeparrot/github-code", split="train", streaming=True)

output_filename = "github_python_subset.jsonl"
num_samples = 100000  # Adjust this number based on your needs and system resources

print(f"Creating a subset of {num_samples} samples from codeparrot/github-code...")

with open(output_filename, "w", encoding="utf-8") as f:
    for i, example in enumerate(dataset):
        if i >= num_samples:
            break
        # The 'code' field contains the actual source code
        code_content = example.get("code")
        if code_content:
            # Write each code snippet as a JSON object on a new line
            # We'll just put the code content directly in a "code" field, matching your C parser
            json_line = json.dumps({"code": code_content})
            f.write(json_line + '\n')

print(f"Subset saved to {output_filename}")
