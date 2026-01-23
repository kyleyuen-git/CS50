import os

home_dir = os.getenv("HOME") 
print(f"Home directory: {home_dir}")

# Get the value, but provide a default if the variable is not set
db_host = os.getenv("DB_HOST", "localhost")
print(f"Database host: {db_host}")

# from openai import OpenAI
# client = OpenAI()

# # Example: Create a chat completion
# response = client.chat.completions.create(
#     model="gpt-4o",
#     messages=[{"role": "user", "content": "Hello world!"}]
# )

# print(response.choices[0].message.content)
