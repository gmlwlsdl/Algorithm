import fs from 'fs'
import path from 'path'
import fetch from 'node-fetch'

const files = process.argv[2]?.split('\n').filter(Boolean)
const API_KEY = process.env.GEMINI_API_KEY

if (!files || files.length === 0) {
  console.log('No C++ files changed.')
  process.exit(0)
}

const PROMPT_TEMPLATE = (code) => `
당신은 알고리즘 및 자료구조에 능숙한 전문가입니다.

아래에 제공된 C++ 코드는 알고리즘 문제의 풀이 코드입니다.
이 코드를 기반으로 다음 작업을 수행하세요.

1. 전체 알고리즘의 핵심 로직 흐름을 분석하고,
   이를 Mermaid.js의 flowchart TD 문법으로 시각화하세요.

2. 시간 복잡도와 공간 복잡도를
   Big-O 표기법과 함께 한국어로 간단히 설명하세요.

출력 규칙:
- Markdown 형식으로 작성하세요.
- Mermaid 다이어그램은 반드시 \`\`\`mermaid 블록을 사용하세요.
- 불필요한 서론은 작성하지 마세요.

[C++ 코드]
\`\`\`cpp
${code}
\`\`\`
`

async function generateAnalysis(filePath) {
  const code = fs.readFileSync(filePath, 'utf8')
  const dir = path.dirname(filePath)
  const outputPath = path.join(dir, 'ANALYSIS.md')

  const res = await fetch(
    'https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=' +
      API_KEY,
    {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        contents: [
          {
            parts: [{ text: PROMPT_TEMPLATE(code) }],
          },
        ],
      }),
    }
  )

  const json = await res.json()
  const text = json.candidates?.[0]?.content?.parts?.[0]?.text

  if (!text) {
    console.error(`Failed to generate analysis for ${filePath}`)
    return
  }

  fs.writeFileSync(outputPath, text, 'utf8')
  console.log(`Generated: ${outputPath}`)
}

for (const file of files) {
  await generateAnalysis(file)
}
