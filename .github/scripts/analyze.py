import os
import subprocess
from google import genai

# 최신 SDK 클라이언트 설정
client = genai.Client(api_key=os.environ["GEMINI_API_KEY"])
MODEL_ID = "gemini-1.5-flash"

def get_target_files():
    """분석할 C++ 파일을 결정합니다."""
    # 1. 최근 커밋 변경 사항 확인
    try:
        output = subprocess.check_output(['git', 'diff', '--name-only', 'HEAD~1', 'HEAD']).decode('utf-8')
        files = [f for f in output.splitlines() if f.endswith(('.cc', '.cpp'))]
    except:
        files = []

    # 2. 변경 사항이 없으면 전체에서 C++ 파일 탐색
    if not files:
        try:
            output = subprocess.check_output(['git', 'ls-tree', '-r', 'HEAD', '--name-only']).decode('utf-8')
            files = [f for f in output.splitlines() if f.endswith(('.cc', '.cpp'))]
        except:
            files = []
            
    return files

def analyze_and_save():
    files = get_target_files()
    
    if not files:
        print("No C++ files found to analyze.")
        return

    for file_path in files:
        if not os.path.exists(file_path): continue
        
        print(f"Analyzing: {file_path}")
        with open(file_path, 'r', encoding='utf-8') as f:
            code = f.read()

        prompt = f"""
        당신은 알고리즘 전문가입니다. 다음 C++ 코드를 분석하여:
        1. 핵심 로직의 흐름도를 Mermaid.js flowchart TD 형식으로 작성하세요.
        2. 시간 복잡도와 공간 복잡도를 한국어로 짧게 설명하세요.
        
        결과는 마크다운 형식으로 작성해주시고, Mermaid 코드는 반드시 ```mermaid 블록으로 감싸주세요.
        코드:
        {code}
        """

        try:
            # 최신 SDK 호출 방식
            response = client.models.generate_content(
                model=MODEL_ID,
                contents=prompt
            )
            
            target_dir = os.path.dirname(file_path)
            analysis_path = os.path.join(target_dir, "ANALYSIS.md")
            
            with open(analysis_path, 'w', encoding='utf-8') as f:
                f.write(f"# 📊 Algorithm Analysis: {os.path.basename(file_path)}\n\n")
                f.write(response.text)
            print(f"Successfully created ANALYSIS.md in {target_dir}")
            
        except Exception as e:
            print(f"Error analyzing {file_path}: {e}")

if __name__ == "__main__":
    analyze_and_save()